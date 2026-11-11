#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else cout << 0;
    if (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2))cout << 1;
    else cout << 0;
    if (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2))
    {
        if (s1.substr(2, 1) <= "C" && s2.substr(2, 1) >= "D") cout << 0;
        else cout << 1;
        if (!(s1.substr(2, 1) <= "C" && s2.substr(2, 1) >= "D" )&& (abs(s1[2] - s2[2]) == 1 || s1[2] == 'D' && s2[2] == 'F'))
        {
            cout << 1;
        }
        else cout << 0;
    }
    return 0;
}
