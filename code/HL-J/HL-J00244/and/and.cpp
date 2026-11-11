#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000000],b[10000000],c[10000000],ans;
int nsa(int qw)
{
    int yu = 2;
    for (int i = 2;i <= qw;i ++)
    {
        yu *= 2;
    }
    return yu;
}
int cmp(int q)
{
    int ni[1000000];
    for (int i = q;i >= 1;i --)
    {
        ni[i] = 0;
        if (ni[i] % 2 == 0)
        {
            break;
        }
        if (i == q)
        {
            ni[i] = q % 2;
        }
        else
        {
            ni[i] = ni[i] % 2;
        }
    }
    for (int i = 1;i <= q;i ++)
    {
        return ni[i];
    }
}
int main ()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0;i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        for (int j = 1;j <= i;j ++)
        {
            c[i] = max(a[i], a[i + 1]);
        }
    }
    for (int i = 0;i < m;i ++)
    {
        b[n-i] = c[n-i];
    }
    for (int i = 0;i <= m;i ++)
    {
        b[i] = cmp(b[i]);
    }
    for (int i = 1;i <= n;i ++)
    {
        if (i == 1)
        {
            ans &= b[i];
        }
    }
    string asd;
    asd = ans + '0';
    for (int i = asd.size();i >= 1;i --)
    {
        int fg;
        fg = asd[i] - 0;
        ans += fg * nsa(i);
    }
    cout << ans;
    return 0;
}
