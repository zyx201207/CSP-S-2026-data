#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1, s1, c2, s2;
bool flag1, flag2, flag3, flag4;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    flag1 = (c1 == c2);
    flag2 = true;
    for (int i = 0; i < 2; i++)
    {
        if (s1[i] != s2[i])
        {
            flag2 = false;
            break;
        }
    }
    flag2 = (flag1 && flag2);
    flag3 = (flag2 && ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')));
    flag4 = (flag3 && (s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]));
    cout << flag1 << flag2 << flag3 << flag4;
    return 0;
}
