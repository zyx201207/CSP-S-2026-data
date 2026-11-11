#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

using ll = long long;

constexpr int maxn = 2e6 + 5;

int c, t, n;
ll d, x[maxn];

namespace X {
    constexpr static const int Maxn = 5005;
    ll dp[Maxn][Maxn], cnt[Maxn][Maxn], ans;
    void solve() {
        cin >> n >> d;
        memset(cnt, 0, sizeof cnt);
        memset(dp, 0x3f, sizeof dp);
        ans = 0;
        for (int i = 1; i <= n; i++) cin >> x[i], dp[i][i] = 0;
        for (int l = 2; l <= n; l++) for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            if (llabs(x[i] - x[j]) <= d) dp[i][j] = cnt[i][j] = 1;
            else for (int k = i + 1; k < j; k++) {
                if (dp[i][k] + dp[k][j] == dp[i][j]) cnt[i][j]++;
                else if (dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = dp[i][k] + dp[k][j] , cnt[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (cnt[i][j] == 2) ans++;
        cout << ans << '\n';
    }
    void main() {
        while (t--) solve();
    }
};

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> t;
    X::main();
    return 0;
}
