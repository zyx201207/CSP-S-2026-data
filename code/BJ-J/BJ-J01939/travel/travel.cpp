#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            if (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')))
            {
                if (!((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A')))
                {
                    cout << "1111" << '\n';
                }
                else
                {
                    cout << "1110" << '\n';
                }
            }
            else
            {
                cout << "1100" << '\n';
            }
        }
        else
        {
            cout << "1000" << '\n';
        }
    }
    else
    {
        cout << "0000" << '\n';
    }
    return 0;
}
