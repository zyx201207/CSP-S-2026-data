#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], cnt, b[200005], num, c[200005], cntt, d[200005], ans, maxn, s = 2147483647;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[++num] = a[i];
        maxn = max(maxn, a[i]);
        s &= a[i];
    }
    if (n == 1)
    {
        cout << maxn;
        return 0;
    }
    if (m == n)
    {
        cout << s;
        return 0;
    }
    for (int i = 30; i >= 0; i--)
    {
        cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if ((a[j] >> i) & 1)
            {
                b[++cnt] = a[j];
            }
        }
        if (cnt < m)
        {
            continue;
        }
        else
        {
            cntt = 0;
            for (int j = 1; j <= num; j++)
            {
                for (int k = 1; k <= cnt; k++)
                {
                    if (b[k] == c[j])
                    {
                        d[++cntt] = b[k];
                    }
                }
            }
            if (cntt >= m)
            {
                ans = d[1]
                for (int j = 2; j <= m; j++)
                {
                    ans &= d[j];
                }
                for (int j = 1; j <= cntt; j++)
                {
                    c[j] = d[j];
                }
            }
        }
    }
    cout << ans;
    return 0;
}
