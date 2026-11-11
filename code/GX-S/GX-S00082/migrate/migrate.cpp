#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 5e3 + 6;

i64 n, d;
i64 a[N], dis[N][N], dp[N][N];

void solve() {
    cin >> n >> d;
    memset(dis, 0x3f, sizeof dis);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dis[i][j] = dis[j][i] = 0;
            else if (abs(a[i] - a[j]) <= d) dis[i][j] = dis[j][i] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] <= 1) dp[i][j] = dp[j][i] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (i == k || j == k) continue;
                if (dis[i][j] == dis[i][k] + dis[k][j]) {
                    dp[i][j] += dp[i][k] * dp[k][j];
                }
            }
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dp[i][j] == 2) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--) solve();

    return 0;
}