# include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const int N = 5e5 + 5;
ll n, m, a[N], b[N], ans = 1;

signed main ()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    ios :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);
    cin >> n >> m; for (int i = 1; i <= n; i++) { cin >> a[i]; } sort (a + 1, a + n + 1); for (int i = 1; i <= n; i++) { b[i] = b[i - 1] + a[i]; }
    for (int i = 2, j = 1; i <= n; i++)
    {
        while (j < i && (i - j) * a[i] - (b[i - 1] - b[j - 1]) > m) { j ++; }
        // cerr << i << " " << j << "\n";
        ans = max <ll> (ans, (i - j + 1ll));
    }
    cout << ans << "\n";
}