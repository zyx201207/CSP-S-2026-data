#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXM = 5e5 + 5;
const int MAXN = 1005;
const int MAXD = 25;
const int INFI = 2e9 + 1;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[MAXM];
ll dist[MAXN][MAXN];
int ev[MAXM][MAXN];
int eg[MAXM][MAXD], et[MAXM][MAXD], etot[MAXM];

int main() {
    // freopen("subway.in", "r", stdin);
    // freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int x, t;
            cin >> x >> t;
            eg[x][++etot[x]] = i;
            et[x][etot[x]] = t;
        }
    }
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ev[i][j] = INFI;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= etot[i]; ++j) {
            for (int k = j + 1; k <= etot[i]; ++k) {
                int x = eg[i][j], y = eg[i][k];
                // cout << i << ' ' << x << ' ' << y << ' ' << et[i][j] + et[i][k] << '\n';
                if (ev[x][y] > et[i][j] + et[i][k]) ev[x][y] = ev[y][x] = et[i][j] + et[i][k];
            }
        }
    }

    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ev[i][j] != INFI) {
                // cout << i << ' ' << j << ' ' << ev[i][j] << '\n';
                dist[i][j] = ev[i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (dist[i][k] == INFL) continue;
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = INFL;
        for (int i = 1; i <= etot[x]; ++i) {
            for (int j = 1; j <= etot[y]; ++j) {
                ans = min(ans, dist[eg[x][i]][eg[y][j]] + et[x][i] + et[y][j]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
}

/*
n 个左部点，m 个右部点，右部点的度数不超过 d
求某两个右部点的最短路

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/