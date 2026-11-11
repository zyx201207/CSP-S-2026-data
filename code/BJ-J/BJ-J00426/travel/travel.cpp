#include<iostream>
#include<cstring>
using namespace std;
string a, b, c, d;
char r, x;
int hr, hx;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    r = b[2], x = d[2], hr = stoi(b.substr(0, 2)), hx = stoi(d.substr(0, 2));
    if(a != c)
    {

        cout << "0000";
        return 0;
    }
    cout << 1;
    if(hr == hx)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if(x <= 'C' && r <= 'C')
    {
        cout << 1;
        if(x == 'A' && r == 'C')
        {
            cout << 0;
        }
        else if(x == 'C' && r == 'A')
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
    }
    else if(x >= 'D' && r >= 'D')
    {
        cout << "11";
    }
    else
    {

        cout << "00";
    }
    return 0;
}