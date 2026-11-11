#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
struct number
{
    long long num;
    char cr;
}a[200010];
number b[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long x = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].num >>a[i].cr;
        b[n - i + 1].num = a[i].num;
        b[n - i + 1].cr = a[i].cr;
        x += a[i].num;
    }
    x /= 2;
    long long xx = 0;
    int y = 1,yy = 1;
    while(xx < x)
    {
        if (a[y].cr == b[yy].cr)
        {
            if (a[y].num == b[yy].num)
            {
                xx += a[y].num;
                y++;
                yy++;
                continue;
            }
            else
            {
                if (a[y].num < b[yy].num)
                {
                    xx += a[y].num;
                    b[yy].num -= a[y].num;
                    y++;
                    continue;
                }
                else
                {
                    xx += b[yy].num;
                    a[y].num -= b[yy].num;
                    yy++;
                    continue;
                }
            }
        }
        else
        {
            if (a[y].num < b[yy].num)
            {
                xx += a[y].num;
                ans += a[y].num;
                b[yy].num -= a[y].num;
                y++;
                continue;
            }
            else
            {
                xx += b[yy].num;
                ans += b[yy].num;
                a[y].num -= b[yy].num;
                yy++;
                continue;
            }
        }
    }
    cout << ans;
    return 0;
}
