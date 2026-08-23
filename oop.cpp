#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    string name;
    int accountNo;
    float balance;
    string history[100];
    int count;

public:
    Bank()
    {
        name = "";
        accountNo = 0;
        balance = 0;
        count = 0;
    }

    void createAccount()
    {
        cout << "\n===== CREATE ACCOUNT =====\n";

        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account Number: ";
        cin >> accountNo;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        history[count++] = "Account Created with Balance = " + to_string((int)balance);

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit()
    {
        float amount;

        cout << "\nEnter Amount to Deposit: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid Amount!\n";
            return;
        }

        balance += amount;

        history[count++] = "Deposit = " + to_string((int)amount);

        cout << "Amount Deposited Successfully.\n";
    }

    void withdraw()
    {
        float amount;

        cout << "\nEnter Amount to Withdraw: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
            return;
        }

        balance -= amount;

        history[count++] = "Withdraw = " + to_string((int)amount);

        cout << "Please Collect Your Cash.\n";
    }

    void checkBalance()
    {
        cout << "\n===== ACCOUNT DETAILS =====\n";

        cout << "Name : " << name << endl;
        cout << "Account Number : " << accountNo << endl;
        cout << "Current Balance : " << balance << endl;
    }

    void transactionHistory()
    {
        cout << "\n===== TRANSACTION HISTORY =====\n";

        if (count == 0)
        {
            cout << "No Transactions Available.\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
};

int main()
{
    Bank b;

    int choice;

    do
    {
        cout << "\n=============================\n";
        cout << "   BANK MANAGEMENT SYSTEM\n";
        cout << "=============================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.createAccount();
            break;

        case 2:
            b.deposit();
            break;

        case 3:
            b.withdraw();
            break;

        case 4:
            b.checkBalance();
            break;

        case 5:
            b.transactionHistory();
            break;

        case 6:
            cout << "\nThank You for Using Bank Management System.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}