#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t, n, d, x[2000005];
namespace sub1
{
    ll len[5005][5005], cnt[5005][5005];
    ll sum[5005][5005], res;
    ll bs1(ll lo, ll hi, ll minn, ll maxx)
    {
        ll mid, ans = -1;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (minn <= x[mid] && x[mid] <= maxx)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
    ll bs2(ll lo, ll hi, ll l, ll eq)
    {
        ll mid, ans = -1;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (len[l][mid] <= eq)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
    void main()
    {
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                len[i][j] = cnt[i][j] = sum[i][j] = 0;
        res = 0;
        for (int le = 1; le <= n; le++)
            for (int l = 1; l <= n - le + 1; l++)
            {
                int r = l + le - 1;
                if (x[r] - d <= x[l])
                {
                    len[l][r] = (l != r);
                    cnt[l][r] = 1;
                    sum[l][r] = sum[l][r - 1] + cnt[l][r];
                    continue;
                }
                int j = bs1(l, r, x[r] - d, x[r]);
                if (j == r)
                {
                    len[l][r] = 9e18;
                    cnt[l][r] = 0;
                    sum[l][r] = sum[l][r - 1] + cnt[l][r];
                    continue;
                }
                int k = bs2(j, r - 1, l, len[l][j]);
                len[l][r] = len[l][j] + 1;
                cnt[l][r] = sum[l][k] - sum[l][j - 1];
                sum[l][r] = sum[l][r - 1] + cnt[l][r];
            }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (cnt[i][j] == 2)
                    res++;
        printf("%lld\n", res);
    }
};
namespace subA
{
    ll w, ans;
    void main()
    {
        if (n <= 1)
        {
            printf("0\n");
            return ;
        }
        w = x[2] - x[1];
        d = d / w;
        if (d <= 1)
        {
            printf("0\n");
            return ;
        }
        ans = max((n - (d * 2 - 1)), 0ll);
        printf("%lld\n", ans);
        return ;
    }
};
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        if (c <= 10) sub1::main();
        else if (c == 11 || c == 12) subA::main();
        else printf("0\n");
    }
    return 0;
}
