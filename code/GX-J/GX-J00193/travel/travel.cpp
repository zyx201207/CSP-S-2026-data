#include <bits/stdc++.h>
using namespace std;
string a, b, c, d, ans, b2, d2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    b2 = b[0];
    d2 = d[0];
    b2 += b[1];
    d2 += d[1];
    if (a == c)
        ans += '1';
    else
        ans += '0';
    if (a == c && b2 == d2)
        ans += '1';
    else
        ans += '0';
    if (a == c && b2 == d2 && ((b[2] == 'A' && d[2] == 'B') || (b[2] == 'A' && d[2] == 'C') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A')|| (b[2] == 'C' && d[2] == 'B')|| (b[2] == 'F' && d[2] == 'D')|| (b[2] == 'D' && d[2] == 'F')))
        ans += '1';
    else
        ans += '0';
    if (a == c && b2 == d2 && ((b[2] == 'A' && d[2] == 'B') || (b[2] == 'A' && d[2] == 'C') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A')|| (b[2] == 'C' && d[2] == 'B')|| (b[2] == 'F' && d[2] == 'D')|| (b[2] == 'D' && d[2] == 'F')) && ((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'B') || (b[2] == 'D' && d[2] == 'F')|| (b[2] == 'F' && d[2] == 'D')))
        ans += '1';
    else
        ans += '0';
    cout << ans;
    return 0;
}
