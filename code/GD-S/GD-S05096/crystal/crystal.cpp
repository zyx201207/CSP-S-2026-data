#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N], sum[N];
bool check(int r, int mid, int val, int m)
{
    // cerr << r - mid + 1 * val << ' ' << sum[r] - sum[mid - 1] << ' ' << m << '\n';
    return (r - mid + 1) * val - (sum[r] - sum[mid - 1]) <= m;
}
int ask(int l, int r, int val, int m)
{
    if (r < l)
        return 0;
    int mid, ans = 0, R = r;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(R, mid, val, m))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    // cerr << l << ' ' << R << ' ' << ans << '\n';
    return R - ans + 1;
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (i = 1; i <= n; i++)
    {

        sum[i] = a[i] + sum[i - 1];
    }
    int ans = 1;
    for (i = 1; i <= n; i++)
    {
        ans = max(ans, ask(1, i - 1, a[i], m) + 1);
    }
    cout << ans;
    return 0;
}