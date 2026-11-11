#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans = 1;
bool flag1 = 1;
void zuo1()
{
    long long cha = a[2] - a[1];
    for (int i = 2;i <= n;i++)
    {
        if (m > 0)
        {
            m -= (i - 1) * cha;
            ans = i;
        }
        else
        {
            break;
        }
    }
    if (m < 0)
    {
        if ((-1 * m) % cha == 0)
        {
            ans -= (-1 * m) / cha;
        }
        else
        {
            ans -= ((-1 * m) / cha + 1);
        }
    }
}
bool check(int x)
{
    long long s = m;
    for (int i = 1;i <= x;i++)
    {
        s = s - a[x] + a[i];
    }
    return s >= 0;
}
void zuo2()
{
    int l = 1,r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
}
void solve()
{
    if (flag1)
    {
        zuo1();
    }
    else
    {
        zuo2();
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    long long c = a[2] - a[1];
    for (int i = 2;i <= n;i++)
    {
        if (a[i] - a[i - 1] != c)
        {
            flag1 = 0;
        }
    }
    solve();
    cout << ans;
    return 0;
}
