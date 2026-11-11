#include <bits/stdc++.h>
using namespace std;
namespace csps {
    typedef long long ll;
    const int MAXN = 500 + 5;
    const int MAXM = 5e5 + 5;
    int c, n, m, d, q, w[MAXM];
    ll dis[MAXN][MAXN];
    struct node {
        int v, w;
    };
    vector<node> to[MAXM];
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        cin >> c >> n >> m >> d >> q;
        for (int i = 1; i <= m; i++) {
            cin >> w[i];
        }
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 1; i <= n; i++) {
            dis[i][i] = 0;
            int k;
            cin >> k;
            while (k--) {
                int x, w;
                cin >> x >> w;
                to[x].push_back({i, w});
            }
        }
        for (int i = 1; i <= m; i++) {
            for (node _x : to[i]) {
                for (node _y : to[i]) {
                    int x = _x.v, xw = _x.w;
                    ll y = _y.v, yw = _y.w;
                    if (x != y) {
                        dis[x][y] = dis[y][x] = min(dis[x][y], xw + yw);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            ll ans = dis[0][0];
            for (node a : to[x]) {
                for (node b : to[y]) {
                    ans = min(ans, dis[a.v][b.v] + a.w + b.w);
                }
            }
            cout << ans + w[x] + w[y] << "\n";
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    csps::main();
    return 0;
}