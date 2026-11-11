#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
bool a, b, c, d;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> c2 >> s1 >> s2;
    if(c1 == s1)
    {
        a = 1;
    }
    if(c2[0] == s2[0] && c2[1] == s2[1] && a == 1)
    {
        b = 1;
    }
     if(c2[0] == s2[0] && c2[1] == s2[1] && a == 1 && b == 1)
    {
        c = 1;
    }
    if((s2[2] == 'D' && c2[2] == 'F') || (c2[2] == 'D' && s2[2] == 'F') && a == 1 && b == 1 && c == 1)
    {
        d = 1;
    }
    if((s2[2] == 'B' && c2[2] == 'A') || (c2[2] == 'B' && s2[2] == 'A') && a == 1 && b == 1 && c == 1)
    {
        d = 1;
    }
    if((s2[2] == 'B' && c2[2] == 'C') || (c2[2] == 'B' && s2[2] == 'C') && a == 1 && b == 1 && c == 1)
    {
        d = 1;
    }
    cout << a << b << c << d;
    return 0;
}
