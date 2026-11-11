#include <bits/stdc++.h>

using namespace std;

int ans1,ans2,ans3,ans4;

int main()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin >> a >> c >> b >> d;
    if (a == b)
        ans1 = 1;
    else
        ans1 = 0;
    if (c[0] == d[0] && c[1] == d[1] && ans1 == 1)
    {
        ans2 = 1;
    }
    else
    {
        ans2 = 0;
    }
    if(ans1 == 1&&ans2 == 1&&((c[2] <= 'C' && d[2] <= 'C')||(c[2] > 'C' && d[2] >'C')))
        ans3 =1;
    else
        ans3 = 0;
    int cc = d[2] - c[2];
    if (cc > 0)
         cc = cc;
    if (cc < 0)
        cc = -1 * cc;
    if (ans3 == 1 && cc == 1)
        ans4 = 1;
    else
        ans4 = 0;
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
