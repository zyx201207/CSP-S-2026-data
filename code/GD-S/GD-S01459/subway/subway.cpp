#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 10, M = 5e5 + 10;

int c, n, m, d, q;
int w[M];
vector<pair<int, int>> G[M];

long long f[N][N];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int a, t; cin >> a >> t;

            G[a].emplace_back(i, t);
        }
    }

    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) f[i][i] = 0;

    for(int i = 1; i <= m; i++) {
        int siz = G[i].size();
        for(int j = 0; j < siz; j++) {
            auto &[u, d] = G[i][j];
            for(int k = j + 1; k < siz; k++) {
                auto &[v, d0] = G[i][k];
                f[u][v] = f[v][u] = min(f[u][v], 1ll * d + d0);
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    while(q--) {
        int x, y; cin >> x >> y;
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for(auto &[i, d] : G[x]) {
            for(auto &[j, d0] : G[y]) {
                ans = min(ans, f[i][j] + w[x] + w[y] + d + d0);
            }
        }

        cout << ans << '\n';
    }
}