#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, M = 500005, D = 21, INF = 1e18;

vector<pair<int, int> > pass[M];

int g[N][N];

int w[M];
int c, n, m, d, q, x, y, ans;

signed main() {
    // convert each subway line to a dot!
    // Complexity: O(n^3+d^2*q)
    // finished in 15:13

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1, k, a, t; i <= n; i++) {
        cin >> k;
        for(int j = 1; j <= k; j++) {
            cin >> a >> t;
            pass[a].push_back(make_pair(i, t));
        }
    }

    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i++) g[i][i] = 0;

    for(int i = 1; i <= m; i++) {
        for(int id1 = 0; id1 < pass[i].size(); id1++) {
            for(int id2 = 0; id2 <= pass[i].size(); id2++) {
                if(id1 == id2) continue;
                g[pass[i][id1].first][pass[i][id2].first] = min(g[pass[i][id1].first][pass[i][id2].first], pass[i][id1].second + pass[i][id2].second);
            }
        }
    }

    // floyd

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    while(q--) {
        ans = INF;
        cin >> x >> y;
        for(int id1 = 0; id1 < pass[x].size(); id1++) {
            for(int id2 = 0; id2 < pass[y].size(); id2++) {
                ans = min(ans, w[x] + w[y] + g[pass[x][id1].first][pass[y][id2].first] + pass[x][id1].second + pass[y][id2].second);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
