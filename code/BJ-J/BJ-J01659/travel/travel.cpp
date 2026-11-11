#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if (a != c)
    {
        cout << "0000";
        return 0;
    }
    else
        cout << 1;
    if (b > d)
        swap(b, d);
    int b0 = 0, c0 = 0;
    bool flag2 = false, flag3 = false, flag4 = false;
    char b1 = b[0], b2 = b[1], b3 = b[2];
    char d1 = d[0], d2 = d[1], d3 = d[2];
    if (b1 == d1 && b2 == d2)
        flag2 = true;
    if (flag2 && ((b3 <= 'C' && d3 <= 'C') || (b3 > 'C' && d3 > 'C')))
        flag3 = true;
    if (flag3)
    {
        if (b3 == 'A' && d3 == 'B') flag4 = true;
        if (b3 == 'B' && d3 == 'C') flag4 = true;
        if (b3 == 'D' && d3 == 'F') flag4 = true;
    }
    cout << flag2 << flag3 << flag4;
    return 0;
}