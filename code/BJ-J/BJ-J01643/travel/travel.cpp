#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    string ans = "0000";

    if (a == c) ans[0] = '1';

    string p1 = "" + b[0] + b[1];
    string p2 = "" + d[0] + d[1];

    if (a == c)
    {

        if (p1 == p2) ans[1] = '1';

        if (p1 == p2 && (b[2] <= 'C') == (d[2] <= 'C'))
        {
            ans[2] = '1';
        }

        if (p1 == p2 && abs(b[2] - d[2]) <= 1 &&
            !((b[2] == 'C' && d[2] == 'D') ||
             (b[2] == 'D' && c[2] == 'C')))
        {
            ans[3] = '1';
        }
    }
    cout << ans;
    return 0;
}
