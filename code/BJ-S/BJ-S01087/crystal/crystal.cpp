#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 5e5 + 5;

long long a[N], sa[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (1ll * a[i] * (i - mid + 1) - sa[i] + sa[mid - 1] <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - r + 1);
    }
    printf("%d", ans);
    return 0;
}