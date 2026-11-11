#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if (s1[0] != s2[0] || s1[1] != s2[1])
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
    {
        cout << 1;
        char a = s1[2], b = s2[2];
        if ((a == 'A' && b == 'B') || (a == 'B' && b == 'A') || (a == 'B' && b == 'C') || (a == 'C' && b == 'B') || (a == 'D' && b == 'F') || a == 'F' && b == 'D')
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        return 0;
    }
    cout << "00";
    return 0;
}
