#include <bits/stdc++.h>
using namespace ctd;
long long n,a[3000000005],b[3000000005],m,num = 1,maxn = -114514,sum = 1;
viod d(int x,int y)
{
    for (int i = 1;i<= y - 1;i++)
    {
        if (a[i] = a[i + 2])
        {
            i += sum;
        }
        if ((maxn & a[i + 3]) > maxn)
        {
            maxn = (maxn & a[i + 3]);
            sum++;
        }
        d(y - 2);
    }
    return maxn;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    for (int i = m;i >= 1;i--)
        num *= (n - i);
    for (int i = 1;i <= m;i++)
    {
        b[i] = a[i];
    }
    for (int i = 1;i < num;i++)
    {
        if ((a[i] & a[i + 1]) > maxn)
        {
            maxn = (a[i] & a[i + 1]);
        }
        if (i >= 2)
        {
            d(n,m);
        }
    }
    cout<< maxn;
    return 0;
}
