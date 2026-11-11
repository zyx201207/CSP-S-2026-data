#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define len 500005

ll a[len], sum[len];
ll n, m;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld %lld ", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if (m == 0)
    {
        printf("0");
        return 0;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        sum[i] = a[i] + sum[i - 1];
    ll i = 1, j = 0, ans = 0;
    while (i <= n)
    {
        ll cnt = a[i] * (i - j) - (sum[i] - sum[j]);
        if (cnt <= m)
        {
            ans = max(ans, i - j);
            i++;
        }
        else if (cnt > m)
        {
            j++;
        }

    }
    printf("%lld", ans);
    return 0;
}
