#include<string>
#include<iostream>
using namespace std;
int main()
{
    int a, b;
    string a1,b1;
    cin >> a >> a1;
    cin >> b >> b1;
    if(a == b) cout << "1";
    else
    {
        cout << "0";
    }
    if(a1[1] == b1[1]) cout << "1";
    else
    {
        cout << "0";
    }
    int c = a1[2] - '0',d = b1[2] - '0';
    if(c - d == 1 || c - d == 2) cout << "1";
    else if(d - c == 1 || d - c == 2) cout << "1";
}
