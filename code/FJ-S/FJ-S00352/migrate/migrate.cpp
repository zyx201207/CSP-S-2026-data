#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 505;

int n, f[N][N], g[N][N];
i64 d, x[1000010];

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = N, g[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) if (x[j] - x[i] <= d) {
            f[i][j] = f[j][i] = 1;
            g[i][j] = g[j][i] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[k][i] + f[k][j] < f[i][j]) {
                    f[i][j] = f[k][i] + f[k][j];
                    g[i][j] = g[k][i] * g[k][j];
                } else if (f[k][i] + f[k][j] == f[i][j]) {
                    g[i][j] += g[k][i] * g[k][j];
                }
                if (g[i][j] > 3) g[i][j] = 3;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) ans += g[i][j] == 2;
    }
    cout << ans << "\n";
}

void solve2() {
    int p = -1;
    for (int i = 1; i <= n; i++) if (x[i] - x[1] > d) {
        p = i;
        break;
    }
    if (p < 4) {
        cout << "0\n";
        return;
    }
    int len = 2 * (p - 2);
    cout << n - len + 1 << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        if (n <= 300) solve();
        else solve2();
    }
}