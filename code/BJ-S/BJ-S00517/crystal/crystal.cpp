#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    int l = 1, cur = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
        {
            cur += (a[i] - a[i - 1]) * (i - l);
        }
        while (cur > m)
        {
            cur -= (a[i] - a[l]);
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%lld", ans);
    return 0;
}