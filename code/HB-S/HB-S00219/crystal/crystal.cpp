// ++rp
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';
#define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int l = 1, r = 1; r <= n; l++) {
        if (r < l)
            r = l;
        while (r < n && a[r + 1] * (r - l + 2) - (s[r + 1] - s[l - 1]) <= m) {
            r++;
        }
        if (a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m)
            ans = max(ans, r - l + 1);
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
// [0, 100] + [0, 32] + [0, 24]