#include <iostream>
using namespace std;

class Item //item class 
{
protected:
	//shared attributes
	int ItemNumber;
	int Code;
	int Color;
	int Brand;
	double Height;
	double Length;
	double Width;
	double Weight;
	double Price;
	int Type;
public:
	Item(); // empty constructor
	virtual ~Item(); // deconstructor
	virtual void display(ostream& s); // display 
	friend ostream& operator<< (ostream& s, Item& p); // ostream operator<<
	Item(const Item& i); // copy constructor
	void copy(const Item& i); // copy function
	void operator= (const Item& i); // operator=
	Item(int itemNumber, int code, int color, int brand, double height, double length,
		double width, double weight, double price, int type); // nonempty constructor
	double getPrice();//get function for price
	int getBrand();//get function for brand
	double getHeight();//get function for height
	double getLength();//get function for length
	double getWidth();//get function for width
	double getWeight();//get function for weight
	int getColor();//get function for color
	int getType();//get function for type
	int getCode();//get function for code
	int getItemNumber();//get function for ItemNumber
};

//initialize empty fields to 0
Item::Item() {
	ItemNumber = 0;
	Code = 0;
	Color = 0;
	Brand = 0;
	Height = 0.0;
	Length = 0.0;
	Width = 0.0;
	Weight = 0.0;
	Price = 0.0;
	Type = 0;
};

//item deconstructor
Item::~Item() {

}

//item display function
void Item::display(ostream& s) {
	cout << "hi" << endl;
}

//item ostream operator<<
ostream& operator<< (ostream& s, Item& p) {
	p.display(s);
	return s;
}

//item copy function
void Item::copy(const Item& i) {
	ItemNumber = i.ItemNumber;
	Code = i.Code;
	Color = i.Color;
	Brand = i.Brand;
	Height = i.Height;
	Length = i.Length;
	Width = i.Width;
	Weight = i.Weight;
	Price = i.Price;
	Type = i.Type;

}

//item copy constructor
Item::Item(const Item& i) {
	copy(i);
}

//item operator=
void Item::operator= (const Item& i) {
	copy(i);
}

//assign values to attributes
Item::Item(int itemNumber, int code, int color, int brand, double height, double length, double width,
	double weight, double price, int type) {
	ItemNumber = itemNumber;
	Code = code;
	Color = color;
	Brand = brand;
	Height = height;
	Length = length;
	Width = width;
	Weight = weight;
	Price = price;
	Type = type;
};


//returns the price
double Item::getPrice() {
	return Price;
}

//returns the height
double Item::getHeight() {
	return Height;
}

//returns the length
double Item::getLength() {
	return Length;
}

//returns the width
double Item::getWidth() {
	return Width;
}

//returns the weight
double Item::getWeight() {
	return Weight;
}

//returns the code
int Item::getCode() {
	return Code;
}

//returns the color
int Item::getColor() {
	return Color;
}

//returns the brand
int Item::getBrand() {
	return Brand;
}

//returns the type
int Item::getType() {
	return Type;
}

//returns the item number
int Item::getItemNumber() {
	return ItemNumber;
}

//pens class Item subclass
class Pens : public Item
{
protected:
	//unique pen attributes
	int PacketSize;
	bool AssortedInk;
public:
	Pens();//empty constructor
	virtual ~Pens();//deconstructor
	Pens(const Pens& p);
	void copy(const Pens& p);
	void operator= (const Pens& p);
	Pens(int itemNumber, int code, int color, int brand, double height, double length,
		double width, double weight, double price, int type, bool assortedInk, int packetSize);// nonempty constructor
	void display(ostream& s);//display method
	bool getAssortedInk();
	int getPacketSize();

};

//pens empty constructor
Pens::Pens()//initialize empty fields to 0
{
	PacketSize = 0;
	AssortedInk = 0;
}

//pens deconstructor
Pens::~Pens() {

}

//pens copy function
void Pens::copy(const Pens& p) {
	PacketSize = p.PacketSize;
	AssortedInk = p.AssortedInk;
}

//pens copy constructor
Pens::Pens(const Pens& p) : Item(p) {
	copy(p);
}

//pens operator=
void Pens::operator= (const Pens& p) {
	copy(p);
}

//assign values nonempty pens constructor
Pens::Pens(int itemNumber, int code, int color, int brand, double height, double length,
	double width, double weight, double price, int type, bool assortedInk, int packetSize) :
	Item(itemNumber, code, color, brand, height, length, width, weight, price, type) {

	PacketSize = packetSize;
	AssortedInk = assortedInk;

}

//returns the assorted ink
bool Pens::getAssortedInk() {
	return AssortedInk;
}

//returns the packet size
int Pens::getPacketSize() {
	return PacketSize;
}

//pens display method
void Pens::display(ostream& s) {
	s << "Item #: " << getItemNumber() << " is a Pen,";
	switch (Color) {
		//four cases for color
	case 1:
		cout << " Color: Red, ";
		break;
	case 2:
		cout << " Color: Blue, ";
		break;
	case 3:
		cout << " Color: Green, ";
		break;
	case 4:
		cout << " Color: Black, ";
		break;
	}
	switch (getBrand()) {
		//four cases for brand
	case 1:
		cout << "Brand: Pilot, ";
		break;
	case 2:
		cout << "Brand: Paper mate, ";
		break;
	case 3:
		cout << "Brand: Uni-ball, ";
		break;
	case 4:
		cout << "Brand: Sharpie, ";
		break;
	}
	// print double values
	cout << "Height: " << getHeight() << ", Length: " << getLength() << ", Width: " << getWidth()
		<< ", Weight: " << getWeight() << ", Price: " << getPrice();
	switch (getType()) {
		//four cases for type
	case 1:
		cout << ", Type: Ball Point, ";
		break;
	case 2:
		cout << ", Type: Roller Ball, ";
		break;
	case 3:
		cout << ", Type: Fountain, ";
		break;
	case 4:
		cout << ", Type: Calligraphy, ";
		break;
	}
	switch (getAssortedInk()) {
		//two cases for Assorted Ink
	case 0:
		cout << "Assorted Ink: No, ";
		break;
	case 1:
		cout << "Assorted Ink: Yes, ";
		break;
	}
	cout << "Packet Size: " << getPacketSize() << endl;
}

class Printer : public Item //printer class Item subclass
{
protected:
	//unique printer attributes
	int TrayCapacity;
	bool Network;
public:
	Printer();//empty constructor
	virtual ~Printer();//deconstructor
	Printer(const Printer& p);
	void copy(const Printer& p);
	void operator= (const Printer& p);
	Printer(int itemNumber, int code, int color, int brand, double height, double length, double width,
		double weight, double price, int type, bool network, int trayCapacity);
	void display(ostream& s);//display method

};

Printer::Printer()//initialize empty fields to 0
{
	TrayCapacity = 0;
	Network = 0;
}

Printer::~Printer() {

}

void Printer::copy(const Printer& p) {
	TrayCapacity = p.TrayCapacity;
	Network = p.Network;
}

Printer::Printer(const Printer& p) : Item(p) {
	copy(p);
}

void Printer::operator= (const Printer& p) {
	copy(p);
}
//assign values
Printer::Printer(int itemNumber, int code, int color, int brand, double height, double length, double width,
	double weight, double price, int type, bool network, int trayCapacity) :Item(itemNumber, code, color,
		brand, height, length, width, weight, price, type) {
	TrayCapacity = trayCapacity;
	Network = network;
}

//printer display method
void Printer::display(ostream& s) {
	s << "Item #: " << getItemNumber() << " is a Printer, ";
	switch (getColor()) {
	case 1:
		cout << "Color: Black, ";
		break;
	case 2:
		cout << "Color: White, ";
		break;
	}
	switch (getBrand()) {
	case 1:
		cout << "Brand: Dell, ";
		break;
	case 2:
		cout << "Brand: HP, ";
		break;
	case 3:
		cout << "Brand: Cannon, ";
		break;
	case 4:
		cout << "Brand: Brother, ";
		break;
	}
	cout << "Height: " << getHeight() << ", Length: " << getLength() << ", Width: " << getWidth()
		<< ", Weight: " << getWeight() << ", Price: " << getPrice();
	switch (getType()) {
	case 1:
		cout << ", Type: All-In-One, ";
		break;
	case 2:
		cout << ", Type: Laser, ";
		break;
	case 3:
		cout << ", Type: InkJet, ";
		break;
	}
	switch (Network) {
	case 0:
		cout << "Network: No, ";
		break;
	case 1:
		cout << "Network: Yes, ";
		break;
	}
	cout << "Tray Capacity: " << TrayCapacity << endl;
}

class SafeBox : public Item//safebox class Item subclass
{
public:
	//unique safebox attributes
	bool ElectronicLock;
	bool FireResistant;
	SafeBox();//empty constructor
	virtual ~SafeBox();//deconstructor
	SafeBox(const SafeBox& s);
	void copy(const SafeBox& s);
	void operator= (const SafeBox& p);
	SafeBox(int itemNumber, int code, int color, int brand, double height, double length, double width,
		double weight, double price, int type, bool fireResistant, bool electronicLock);//nonempty constructor
	void display(ostream& s);//display method
};

SafeBox::SafeBox()//initialize empty values to 0
{
	ElectronicLock = 0;
	FireResistant = 0;
}

SafeBox::~SafeBox() {

}

void SafeBox::copy(const SafeBox& s) {
	ElectronicLock = s.ElectronicLock;
	FireResistant = s.FireResistant;
}

SafeBox::SafeBox(const SafeBox& s) : Item(s) {
	copy(s);
}

void SafeBox::operator= (const SafeBox& s) {
	copy(s);
}

//assign values
SafeBox::SafeBox(int itemNumber, int code, int color, int brand, double height, double length, double width,
	double weight, double price, int type, bool fireResistant, bool electronicLock) :Item(itemNumber, code, color,
		brand, height, length, width, weight, price, type) {
	ElectronicLock = electronicLock;
	FireResistant = fireResistant;
}

//safebox display
void SafeBox::display(ostream& s) {
	s << "Item #: " << getItemNumber() << " is a SafeBox, ";
	switch (getColor()) {
	case 1:
		cout << "Color: Black, ";
		break;
	case 2:
		cout << "Color: Red, ";
		break;
	}
	switch (getBrand()) {
	case 1:
		cout << "Brand: SentrySafe, ";
		break;
	case 2:
		cout << "Brand: First Alert, ";
		break;
	case 3:
		cout << "Brand: Honeywell, ";
		break;
	}
	cout << "Height: " << getHeight() << ", Length: " << getLength() << ", Width: " << getWidth()
		<< ", Weight: " << getWeight() << ", Price: " << getPrice();
	switch (getType()) {
	case 1:
		cout << ", Type: Water Proof, ";
		break;
	case 2:
		cout << ", Type: Wall Mountable, ";
		break;
	case 3:
		cout << ", Type: Desktop, ";
		break;
	}
	switch (FireResistant) {
	case 0:
		cout << "Fire Resistant: No, ";
		break;
	case 1:
		cout << "Fire Resistant: Yes, ";
		break;
	}
	switch (ElectronicLock) {
	case 0:
		cout << "Electronic Lock: No, ";
		break;
	case 1:
		cout << "Electronic Lock: Yes, ";
		break;
	}
	cout << endl;
}

//bag class definition
class Bag //bag class
{
protected:
	Item** myItems;
	int numItems;

public:
	//methods required
	Bag();
	virtual ~Bag();
	friend ostream& operator<< (ostream& s, Bag& p);
	Bag(const Bag& b);
	void copy(const Bag& b);
	void operator= (const Bag& b);
	void addItem(Item* addThis);
	void delItem(int delThis);
	Item** getItems();
	int getNumItems();
};

Bag::Bag() {
	myItems = new Item*[1];
	numItems = 0;
}

Bag::~Bag() {
	if (myItems != NULL)
		delete[] myItems;
}


ostream& operator<< (ostream& s, Bag& p) {

	int noPens = 0;//counts the number of pens in the bag
	int noPrinter = 0;//counts the number of printers in the bag
	int noSafeBox = 0;//counts the number of safeboxes in the bag
	double totalPens = 0.0;//adds up the total price for the pens in the bag
	double totalPrinter = 0.0;//adds up the total price for the printers in the bag
	double totalSafeBox = 0.0;//adds up the total price for the safe boxes in the bag
	double totalPrice = 0.0;//adds up the prices for total price of items in the bag

	s << "There are " << p.getNumItems() << " items in the bag." << endl;
			
	//go through all the items with this loop
	for (int j = 0; j < p.getNumItems(); j++) {
		//check the code of the item and print for each case
		switch ((p.myItems)[j]->getCode()) {
		case 1: {//Pens
			cout << *(static_cast<Pens*>((p.getItems())[j]));
			totalPens += ((p.getItems())[j])->getPrice();
			noPens++;
			break;
		}
		case 2: {//Printers
			cout << *(static_cast<Printer*>((p.getItems())[j]));
			totalPrinter += ((p.getItems())[j])->getPrice();
			noPrinter++;
			break;
		}
		case 3: {//Safe Box
			cout << *(static_cast<SafeBox*>((p.getItems())[j]));
			totalSafeBox += ((p.getItems())[j])->getPrice();
			noSafeBox++;
			break;
		}
		default: cout << "I do not recognize this Item in the Bag" << endl;
		}

	}
		
	//summary for each user
	totalPrice = totalPens + totalPrinter + totalSafeBox;
	cout << "Summary for bag: " << endl;
	cout << "#Pen(s): " << noPens << "  #Printer(s): " << noPrinter << "  #Safe Box(s): " << noSafeBox << endl;
	cout << "The total price for the pen(s): $" << totalPens << endl;
	cout << "The total price for the printer(s): $" << totalPrinter << endl;
	cout << "The total price for the safe box(s): $" << totalSafeBox << endl;
	cout << "The total price for the item(s): $" << totalPrice << endl;

	return s;
}

void Bag::copy(const Bag& b) {
	numItems = b.numItems;
	myItems = new Item*[numItems];
	for (int i = 0; i < numItems; i++) {
		myItems[i] = b.myItems[i];
	}
}

Bag::Bag(const Bag& b){
	copy(b);
}

void Bag::operator= (const Bag& b) {
	copy(b);
}

//add item function for bag
void Bag::addItem(Item* addThis) {
	//check if it is the first item to be added
	if (numItems == 0) {
		myItems[numItems] = addThis;
		numItems++;
	}
	else {
		//copy over items in bag to temp. create a new array one size larger
		Item** temp = myItems;
		numItems++;
		myItems = new Item*[numItems];
		for (int i = 0; i < numItems - 1; i++) { 
			myItems[i] = temp[i];
			temp[i] = NULL; 
		}
		delete [] temp;
		//this adds the new item to the larger array
		myItems[numItems-1] = addThis;
	}
}

//delete item function for bag class
void Bag::delItem(int delThis) {
	int numToDel = 0;//holds the number of items to be deleted
	//go through the items and increment when the item to be deleted is found
	for (int i = 0; i < numItems; i++) {
		if (myItems[i]->getItemNumber() == delThis) {
			numToDel++;
		}
	}
	//if the number of items to be deleted is the same size as the array, create a new empty array of size 1
	if (numToDel == numItems) {
		myItems = new Item*[1];
		numItems = 0;
	}
	//
	else {
		Item** temp = myItems;//temp holds the items currently in the bag

		//create a new array with the size of current 
		//number of items minus number to be deleted
		myItems = new Item*[numItems - numToDel];

		//go though the bag and copy over tiems that don't match the item to be deleted.
		int counter = 0;
		for (int i = 0; i < numItems; i++) {
			if (temp[i]->getItemNumber() != delThis) {
				myItems[counter] = temp[i];
				temp[i] = NULL;
				counter++;
			}
		}

		//change the number of items in the bag
		numItems -= numToDel;
		delete[] temp;
	}
}

Item** Bag::getItems() {
	return myItems;
}

int Bag::getNumItems() {
	return numItems;
}


int findUserIDPosition(int* values, int size, int userID) {
	for (int i = 0; i < size; i++) {
		if (values[i] == userID) {		
			return i;
		}
	}
	return 0;
}

//set character array values to empty
void nullTerminate(char* str, int size) {
	for (int i = 0; i < size; i++)
		str[i] = '\0';
};

void nullTerminateInt(int* values, int size) {
	for (int i = 0; i < size; i++) {
		values[i] = 0;
	}
};

bool checkCommand(char* str) //check the command
{
	return (str[0] == 'A');
};

bool checkUserID(int* users, int size, int userAdd)
{
	for (int i = 0; i < size; i++) {
		if (users[i] == userAdd) {
			return false;
		}
	}
	return true;
};


//main method
int main()
{
	int users[50];//50 maximum users
	int numUsers = 0;//start with 0 users
	Bag* userBag[50]; // users[i] Bag pointer is in userBag[i]
	int bagPos = 0;//position of bag used for adding items
	char command[10];//holds the command string
	int userID;//holds the user ID number
	int itemNumber;//holds the item number
	int quantity;//holds the quantity of the item
	int code;//specifies the type of item
	int color;//determines the color of the item
	int brand;//determines the brand of the item
	double height;//determines the height of the item
	double length;//determines the length of the item
	double width;//determines the width of the item
	double weight;//determines the weight of the item
	double price;//determines the weight of the price
	int type;//determines the type of item
	bool att10;//this is a unique field for the three items
	int att11;//this is the second unique field for the three items


	nullTerminate(command, 10);//clears the command array
	nullTerminateInt(users, 50);

	cin >> command;//read in first attribute
	cout << "File Input: " << endl;
	while (!cin.eof())	//while end of line is not reached
	{
		//read a line from input
		//cin >> command >> quantity >> code >> all other attributes
		if (checkCommand(command))//when command is ADDITEM
		{
			cin >> userID >> itemNumber >> quantity >> code >> color >> brand >> height >> length >> width >>
				weight >> price >> type >> att10 >> att11;
			//print out the line that was read
			cout << command << " " << userID << " " << itemNumber << " " << quantity << " " << code << " " << color << " " << brand << " " << height << " " <<
				length << " " << width << " " << weight << " " << price << " " << type << " " << att10 << " " << att11 << endl;
			
			//when user is not registered in the system
			if (checkUserID(users, 50, userID)) {
				users[numUsers] = userID;
				//create a new bag object and place the pointer to it in position userBag[numUsers]
				userBag[numUsers] = new Bag();
				//Based on code create the appropriate object and store it in the Bag array as described in project description
				//creates an item based on what the value of code is
				switch (code) {
				case 1: //Pens
					for (int i = 0; i < quantity; i++) {
						userBag[numUsers]->addItem(new Pens(itemNumber, code, color, brand, height, length, width, weight, price, type, att10, att11));
					}
					bagPos += quantity;
					break;
				case 2: //Printer
					for (int i = 0; i < quantity; i++) {
						userBag[numUsers]->addItem(new Printer(itemNumber, code, color, brand, height, length, width, weight, price, type, att10, att11));
					}
					bagPos += quantity;
					break;
				case 3: //Safe box
					for (int i = 0; i < quantity; i++) {
						userBag[numUsers]->addItem(new SafeBox(itemNumber, code, color, brand, height, length, width, weight, price, type, att10, att11));
					}
					bagPos += quantity;
					break;
				}
				numUsers++;
			}

			//when user is already in the system
			else {
				//Based on code create the appropriate object and store it in the Bag array as described in project description
				//creates an item based on what the value of code is
				switch (code) {
				case 1: //Pens
					for (int i = 0; i < quantity; i++) {
						userBag[findUserIDPosition(users, 50, userID)]->addItem(new Pens(itemNumber, code, color, brand, height, length, width, weight, price, type, att10, att11));
					}
					bagPos += quantity;
					break;
				case 2: //Printer
					for (int i = 0; i < quantity; i++) {
						userBag[findUserIDPosition(users, 50, userID)]->addItem(new Printer(itemNumber, code, color, brand, height, length, width, weight, price, type, att10, att11));
					}
					bagPos += quantity;
					break;
				case 3: //Safe box
					for (int i = 0; i < quantity; i++) {
						userBag[findUserIDPosition(users, 50, userID)]->addItem(new SafeBox(itemNumber, code, color, brand, height, length, width, weight, price, type, att10, att11));
					}
					bagPos += quantity;
					break;
				}
			}
		}

		//when the command is DELITEM
		else {
			cin >> userID >> itemNumber;
			cout << command << " " << userID << " " << itemNumber << endl;
			userBag[findUserIDPosition(users, 50, userID)]->delItem(itemNumber);

		}
		cin >> command;
	}
	//write code to display each item stored in the Bag array using code described in the project description
	 //Let noItems be the number of Item objects stored (it is the number Item object pointers)
	 //stored in the Bag

	cout << endl;
	cout << "Bag(s) Summary Section:" << endl;

	//print through each user's bag
	for (int i = 0; i < numUsers; i++) {
		cout << endl;
		cout << "Content inside bag for user #: " << users[i] << endl;
		if (userBag[i]->getNumItems() == 0) {
			cout << "User #: " << users[i] << " has an empty bag." << endl;
		}
		else {
			cout << *userBag[i] << endl;
		}
	}
	return 0;
} 