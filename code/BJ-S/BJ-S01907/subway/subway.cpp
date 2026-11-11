#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    int id; ll t;
};
ll a[500005];
vector<node> seg[500005], w[505];
ll f[505][505];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        for (int j = 1; j <= x; j++) {
            int y; ll z; cin >> y >> z;
            w[i].push_back({y, z});
            seg[y].push_back({i, z});
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = 1e18;
    int x, y;
    for (int k = 1; k <= m; k++) {
        for (int i = 0; i < seg[k].size(); i++) {
            for (int j = i + 1; j < seg[k].size(); j++) {
                x = seg[k][i].id, y = seg[k][j].id;
                f[x][y] = min(min(f[x][y], f[y][x]), seg[k][i].t + seg[k][j].t);
                f[y][x] = min(f[y][x], f[x][y]);
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = i, y = j;
            if (w[x].size() > w[y].size()) swap(x, y);
            for (int i = 0; i < w[x].size(); i++) {
                if (v[y][w[x][i].id].first) {
                    f[x][y] = min(f[x][y], v[y][w[x][i].id].second + w[x][i].t);
                }
            }
            f[y][x] = f[x][y];
        }
    }*/
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        cin >> x >> y;
        ll cnt = 1e18;
        for (int i = 0; i < seg[x].size(); i++) {
            for (int j = 0; j < seg[y].size(); j++) {
                cnt = min(cnt, a[x] + a[y] + f[seg[x][i].id][seg[y][j].id] + seg[x][i].t + seg[y][j].t);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
