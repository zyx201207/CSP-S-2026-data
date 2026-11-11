#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll C, T;
ll n, d, ans;
ll x[2000005], f[2000005], g[2000005];

void solve () {
    ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        f[i] = 1e18;
        g[i] = 0;
    }
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[j] = 1e18;
            g[j] = 0;
        }
        f[i] = 0;
        g[i] = 1;
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j - 1; k >= i && (x[j] - x[k] <= d); --k) {
                if (f[j] > f[k] + 1) {
                    f[j] = f[k] + 1;
                    g[j] = g[k];
                } else if (f[j] == f[k] + 1) {
                    g[j] += g[k];
                }
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (g[j] == 2) {
                ans++;
            }
        }
        for (int j = 1; j <= n; ++j) {
            f[j] = 1e18;
            g[j] = 0;
        }
        f[i] = 0;
        g[i] = 1;
        for (int j = i - 1; j >= 1; --j) {
            for (int k = j + 1; k <= i && (x[k] - x[j] <= d); ++k) {
                if (f[j] > f[k] + 1) {
                    f[j] = f[k] + 1;
                    g[j] = g[k];
                } else if (f[j] == f[k] + 1) {
                    g[j] += g[k];
                }
            }
        }
        for (int j = i - 1; j >= 1; --j) {
            if (g[j] == 2) {
                ans++;
            }
        }
    }
    cout << ans / 2 << "\n";
}

int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> T;
    while (T--) {
        solve();
    }
    return 0;
}
