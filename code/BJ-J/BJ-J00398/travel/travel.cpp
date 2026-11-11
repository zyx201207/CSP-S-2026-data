#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;

bool check(char a, char b)
{
    bool flaga, flagb;
    if (a == 'A' || a == 'B' || a == 'C') flaga = 1;
    else flaga = 0;
    if (b == 'A' || b == 'B' || b == 'C') flagb = 1;
    else flagb = 0;
    return flaga == flagb;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << 1;
            if (check(s1[2], s2[2]))
            {
                cout << 1;
                if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
