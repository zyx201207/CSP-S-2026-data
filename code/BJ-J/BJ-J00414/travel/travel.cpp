#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    mp['A'] = mp['B'] = mp['C'] = 1, mp['D'] = mp['F'] = 2;
    int a, b, c, d;
    char c1, c2;
    cin >> a >> b >> c1 >> c >> d >> c2;
    if (a != c)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if (b != d)
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    if (mp[c1] != mp[c2])
    {
        cout << "00";
        return 0;
    }
    cout << 1;
    if (c1 + 1 == c2 || c2 + 1 == c1 || (c1 == 'D' && c2 == 'F') || (c2 == 'D' && c1 == 'F')) cout << 1;
    else cout << 0;
}