#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], s[500005], ans;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int l = 1, r = 1;
    while (l <= n)
    {
        if ((r - l) * a[r] - s[r - 1] + s[l - 1] <= m && r <= n) ans = max(ans, r - l + 1), ++r;
        else ++l;
    }
    cout << ans;
    return 0;
}
// 14:48