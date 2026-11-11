#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], sum[500005];
long long dl;
bool chk(int l, int r)
{
    long long s = -(sum[r] - sum[l - 1]) + dl * 1ll * (r - l + 1);
    // printf("%d->%d: %long longd\n", l, r, s);
    return (s <= m);
}
int ans;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    // printf("test");
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    // for (int i = 1; i <= n; i ++) printf("%d ", a[i]);
    // printf("\n");
    dl = a[1];
    for (int i = 1; i <= n; i ++)
    {
        dl = a[i];
        int l = 1, r = i - 1;
        int mid = 1;
        int res = i;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (chk(mid, i - 1))
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = max(ans, i - res + 1);
    }
    printf("%d\n", ans);
    return 0;
}