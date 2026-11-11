#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, t1, t2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    for (int i = 0; i <= 1; i++)
    {
        t1 += s1[i];
        t2 += s2[i];
    }
    if (c1 == c2 && t1 == t2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (c1 == c2 && t1 == t2)
    {
        if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B'))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    if (c1 == c2 && t1 == t2)
    {
        if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}