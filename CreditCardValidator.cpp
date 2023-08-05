//Credit card number checker
#include < iostream >
using namespace std;



int NumberOfCharactars(long long int CardNumberInput) {
	int pointer{ 0 };
	for (CardNumberInput; CardNumberInput > 0;) {
		if (CardNumberInput % 10 >= 0) {
			pointer = pointer + 1;
			CardNumberInput = CardNumberInput / 10;
		}
	}
	if (pointer == 15) {

		return pointer;

	}
	else if (pointer == 16) {

		return pointer;

	}
	else {

		return pointer;
	}
	
}

int Checksum(long long int CardNumberInput) {
	int checksum;
	//Removing checksum from card number
	checksum = CardNumberInput % 10;
	return checksum;
}

long long int ReverseCard(long long int CardNumberInput) {
	
	//Reverse input algo without checksum

	CardNumberInput = CardNumberInput / 10;
	int reverseTemp;
	long long int ReverseCardNumber(0);
	while (CardNumberInput != 0) {
		reverseTemp = CardNumberInput % 10;
		ReverseCardNumber = (ReverseCardNumber * 10) + reverseTemp;
		CardNumberInput = CardNumberInput / 10;
	}

	return ReverseCardNumber;
}

int LuhnAlgoEven(long long int ReversedCard) {

	//Doubling the value of every second element
	int sum{ 0 }, newVariable, TempVariable(ReversedCard % 10), TempVariable2;
	for (ReversedCard; ReversedCard > 0;) {


		if ((TempVariable * 2) > 10) {
			TempVariable2 = TempVariable % 10 + (TempVariable / 10) % 10;
			sum = sum + TempVariable2;
		}
		else {
			sum = sum + TempVariable;
		}
		ReversedCard = ReversedCard / 100;
		}	for (ReversedCard; ReversedCard > 0;) {
			
			TempVariable = ReversedCard % 10;

			if ((TempVariable * 2) > 10) {
				TempVariable2 = TempVariable % 10 + (TempVariable / 10) % 10;
				sum = sum + TempVariable2;
			}
			else {
				sum = sum + TempVariable;
			}
			ReversedCard = ReversedCard / 100;
		}


	newVariable = sum % 10;
	return newVariable;
}
int LuhnAlgoOdd(long long int ReversedCard) {
	//Doubling the value of every second element
	int sum{ 0 }, newVariable, TempVariable(ReversedCard % 10 ), TempVariable2;
	for (ReversedCard; ReversedCard > 0;) {


		if ((TempVariable * 2) > 10) {
			TempVariable2 = TempVariable % 10 + (TempVariable / 10) % 10;
			sum = sum + TempVariable2;
		}
		else {
			sum = sum + TempVariable;
		}
		ReversedCard = ReversedCard / 100;

	}

	ReversedCard = ReversedCard / 10;
	for (ReversedCard; ReversedCard > 0;) {

		TempVariable = ReversedCard % 10;

		if ((TempVariable * 2) > 10) {
			TempVariable2 = TempVariable % 10 + (TempVariable / 10) % 10;
			sum = sum + TempVariable2;
		}
		else {
			sum = sum + TempVariable;
		}
		ReversedCard = ReversedCard / 100;
	}
	newVariable = sum % 10;
	return newVariable;
}



int main() {

	
	long long int CardNumberInput;
	cout << "Enter credit card number: ";
	cin >> CardNumberInput;
	cout << endl;


	int checksum = Checksum(CardNumberInput);
	long long int ReversedCard = ReverseCard(CardNumberInput);

// For Amex Cards
	if (NumberOfCharactars(CardNumberInput) == 15) {

		
		if (LuhnAlgoEven(ReversedCard) == checksum){
			cout << "Voila! It's Valid" << endl;
		}
		else {
			cout << "Invalid CC" << endl;
		}

	}
// For Visa/Mastercard
	else if (NumberOfCharactars(CardNumberInput) == 16) {
	
		if (LuhnAlgoOdd(ReversedCard) == checksum) {
			cout << "Voila! It's Valid" << endl;
		}
		else {
			cout << "Invalid CC" << endl ;
		}
	}

//Doesn't match format
	else {
		cout << "Error! Check details" << endl;
	};


	cout << "Checksum: " << checksum<<endl;
	cout << "Reversed Card: " << ReversedCard << endl;
	cout << "Algo : " << LuhnAlgoOdd(ReversedCard) << endl;
}
