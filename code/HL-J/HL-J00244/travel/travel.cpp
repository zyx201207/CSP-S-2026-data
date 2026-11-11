#include <bits/stdc++.h>
using namespace std;
int r,x;
string r1,x2;
int main ()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> r >> r1;
    cin >> x >> x2;
    if (r == x)
    {
        cout << 1;
    }
    else
    {
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    if (r1[0] == x2[0] || r1[1] == x2[1])
    {
        cout << 1;
    }
    else
    {
        cout << 0 << 0;
        return 0;
    }
    if (r1[2] == x2[2])
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        return 0;
    }
    if ((r1[2] == 'A' && x2[2] == 'B') || (r1[2] == 'B' && x2[2] == 'C') || (r1[2] == 'D' && x2[2] == 'F'))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
