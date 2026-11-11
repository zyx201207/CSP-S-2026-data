#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 505, M = 5e5 + 5;

int c, n, m, d, q, w[M];
std::vector<std::pair<int, int>> vc[M];
i64 f[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int a, t, j = 1; j <= k; j++) {
            cin >> a >> t;
            for (auto [o, val] : vc[a]) {
                i64 tmp = std::min(f[o][i], i64(val + t));
                f[o][i] = f[i][o] = tmp;
            }
            vc[a].emplace_back(i, t);
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = std::min(f[i][j], f[k][i] + f[k][j]);
            }
        }
    }
    for (int x, y; q--; ) {
        cin >> x >> y;
        i64 ans = 1e18;
        for (auto [i, valx] : vc[x]) {
            for (auto [j, valy] : vc[y]) {
                ans = std::min(ans, valx + valy + f[i][j]);
            }
        }
        cout << ans + w[x] + w[y] << "\n";
    }
}