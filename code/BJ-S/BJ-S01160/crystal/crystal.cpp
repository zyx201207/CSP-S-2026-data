#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], d[N], pre[N], s[N], ans;
int f(int l, int r)
{
    return s[r] - s[l - 1] - (l - 1) * (pre[r] - pre[l - 1]);
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
    {
        d[i] = a[i + 1] - a[i];
        pre[i] = pre[i - 1] + d[i];
        s[i] = s[i - 1] + i * d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i, res = i;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (f(mid, i - 1) <= m) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - res + 1);
    }
    cout << ans;
    return 0;
}
