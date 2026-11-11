#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    char a, b;
    int c, d, e, f;
    cin >> c1 >> s1 >> c2 >> s2;
    a = s1[2];
    b = s2[2];
    if (a == 'A') c = 1;
    if (a == 'B') c = 2;
    if (a == 'C') c = 3;
    if (a == 'D') c = 4;
    if (a == 'F') c = 5;
    if (b == 'A') d = 1;
    if (b == 'B') d = 2;
    if (b == 'C') d = 3;
    if (b == 'D') d = 4;
    if (b == 'F') d = 5;
    if (1 <= c && c <= 3) e = 0;
    else e = 1;
    if (1 <= d && d <= 3) f = 0;
    else f = 1;
    if (c1 == c2)
    {
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << "1";
            if (e + f == 1) cout << "00";
            else
            {
                cout << "1";
                if (abs(c - d) == 1) cout << "1";
                else cout << "0";
            }
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
