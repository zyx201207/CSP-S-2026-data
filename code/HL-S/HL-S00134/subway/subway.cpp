#include <cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
bool ___end;
int w_to_land[500005];
vector<pair<int, int>> of_mtl[500005];
int mat[505][505];
bool ___begin;
signed main() {
    // cerr << (double)(&___end - &___begin) / 1024 / 1024 << '\n';
    // int ____begin = clock();
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio();
    int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w_to_land[i];
    for (int i = 0; i < 505; i++) for (int j = 0; j < 505; j++) mat[i][j] = inf;
    for (int i = 1; i <= n; i++) mat[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        while (k--) {
            int u, w; cin >> u >> w;
            for (pair<int, int> p: of_mtl[u]) {
                mat[p.first][i] = mat[i][p.first] = min(mat[i][p.first], w + p.second);
            }
            of_mtl[u].push_back({i, w});
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        int ans = inf;
        for (pair<int, int> p: of_mtl[x]) {
            int u = p.first, w1 = p.second;
            for (pair<int, int> q: of_mtl[y]) {
                int v = q.first, w2 = q.second;
                ans = min(ans, w1 + w2 + mat[u][v]);
            }
        }
        ans += w_to_land[x] + w_to_land[y];
        cout << ans << '\n';
    }
    // int ____end = clock();
    // cerr << (double)(____end - ____begin) / CLOCKS_PER_SEC << '\n';
}