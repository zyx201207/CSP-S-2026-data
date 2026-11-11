#include <bits/stdc++.h>
using namespace std;
int c1, s1, c2, s2;
char ss1, ss2;
map<char, int> mp;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    mp['A'] = mp['B'] = mp['C'] = 0, mp['D'] = mp['F'] = 1;
    cin >> c1 >> s1 >> ss1 >> c2 >> s2 >> ss2;
    if (c1 != c2) cout << "0000";
    else if (s1 != s2) cout << "1000";
    else if (mp[ss1] != mp[ss2]) cout << "1100";
    else
    {
        if (ss1 == 'A' && ss2 == 'B' || ss1 == 'B' && ss2 == 'A' || ss1 == 'B' && ss2 == 'C' || ss1 == 'C' && ss2 == 'B' || ss1 == 'D' && ss2 == 'F' || ss1 == 'F' && ss2 == 'D') cout << "1111";
        else cout << "1110";
    }
    return 0;
}
