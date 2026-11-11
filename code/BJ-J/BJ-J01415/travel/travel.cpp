#include <bits/stdc++.h>
using namespace std;
int a, c;
string b, d;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if(a == c && a != 1 && a != 16)
        cout << "1 ";
    else
    {
        cout << "0 0 0 0";
        return 0;
    }
    if(b[1] * 10 + b[2] == d[1] * 10 + d[2])
        cout << "1 ";
    else
    {
        cout << "0 0 0";
        return 0;
    }
    if(b[3] == 'C' && d[3] == 'D')
        cout << "0 0";
    else
    {
        cout << "1 ";
        return 0;
    }
    if(b[3] >= 'A' && d[3] == 'C')
        cout << "0";
    else
        cout << "1";
    return 0;
}