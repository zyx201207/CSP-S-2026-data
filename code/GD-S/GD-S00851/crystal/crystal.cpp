#include <cstdio>
#include <algorithm>

using namespace std;

int n, l, r, mid, ans;
long long m, a[500005], sum[500005];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + a[i];
        l = 1;
        r = i - 1;
        while (l < r)
        {
            mid = l + r >> 1;
            if ((long long)(i - mid + 1) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d", ans);
    return 0;
}