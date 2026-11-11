#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a = 4;
    cin >> c1 >> s1 >> c2 >> s2;
    int r1 = s1[2], r2 = s2[2];
    if (c1 == c2)
    {
        cout << 1;
        a--;
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << 1;
            a--;
            if (r1 <= 'C' && r2 <= 'C' || r1 >= 'D' && r2 >= 'D')
            {
                cout << 1;
                a--;
                int r = r1 - 'A' - (r2 - 'A');
                if (r == 1 || r == -1)
                {
                    cout << 1;
                    a--;
                }
            }
        }
    }
    while (a > 0)
    {
        cout << 0;
        a--;
    }
    return 0;
}
