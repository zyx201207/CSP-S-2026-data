#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005];
ll sum[500005], res = 1;
inline bool check(ll l, ll r)
{
    ll ori = sum[r] - sum[l - 1], tar = a[r] * (r - l + 1);
    return ori + m >= tar;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int r = 1; r <= n; r++)
    {
        ll lo = 1, hi = r, mid, ans = r;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (check(mid, r))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        res = max(res, r - ans + 1);
    }
    printf("%lld\n", res);
    return 0;
}
