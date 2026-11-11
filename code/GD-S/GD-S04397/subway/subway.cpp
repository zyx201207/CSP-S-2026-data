#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 510, M = 500010;
constexpr ll inf = 1e18;
int c, n, m, d, q;
ll w[M];
vector<pair<int, ll>> a[N];
vector<pair<int, ll>> b[M];
ll f[N][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) f[i][j] = inf;
        f[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j].first >> a[i][j].second;
            b[a[i][j].first].push_back({i, a[i][j].second});
        }
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int pos1 = 0, pos2 = 0;
            while (pos1 < a[i].size() && pos2 < a[j].size()) {
                if (a[i][pos1].first == a[j][pos2].first) {
                    f[j][i] = f[i][j] = min(f[i][j], a[i][pos1].second + a[j][pos2].second);
                    pos1++, pos2++;
                } else if (a[i][pos1].first < a[j][pos2].first) pos1++;
                else pos2++;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = inf;
        for (auto [i, t1] : b[x]) {
            for (auto [j, t2] : b[y]) {
                ans = min(ans, f[i][j] + t1 + t2);
            }
        }
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
}