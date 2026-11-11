#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a != c)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if(b[0] != d[0] || b[1] != d[1])
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    if(b[2] < 68 && d[2] > 67)
    {
        cout << "00";
        return 0;
    }
    cout << 1;
    if(b[2] == 'A' && d[2] == 'C' || b[2] == 'C' && d[2] == 'A') cout << 0;
    else cout << 1;
    return 0;
}