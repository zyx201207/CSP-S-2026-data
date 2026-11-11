#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
int n, m, a[maxn], sum[maxn];
signed main ()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        while (l < r)
        {
            int mid = l + r >> 1;
            if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
