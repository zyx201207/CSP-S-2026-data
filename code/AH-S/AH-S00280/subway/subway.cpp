#include <bits/stdc++.h>
using namespace std;

const int MAXM = 500005;
const int MAXN = 505;

struct Subway { int id, dis; };

int c, n, m, d, q;

int w[MAXM];
long long dis[MAXN][MAXN];
vector<Subway> sub[MAXM]; 

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; ++i) scanf("%d", &w[i]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) dis[i][j] = 1e16;
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;

    for (int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            int x, y;
            scanf("%d %d", &x, &y);
            sub[x].push_back( (Subway) {i, y} );
        }
    }

    for (int i = 1; i <= m; ++i) {
        //for (int j = 0; j < (int) sub[i].size(); ++j)
            //cout << sub[i][j].id << " " << sub[i][j].dis << endl;
        //cout << endl;
        for (int j = 0; j < (int) sub[i].size(); ++j) {
            for (int k = 0; k < j; ++k) {
                int u = sub[i][j].id;
                int v = sub[i][k].id;
                //cout << u << " " << v << endl;
                dis[v][u] = dis[u][v] = min(1ll * sub[i][j].dis + 1ll * sub[i][k].dis, dis[u][v]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
            dis[u][v] = min(dis[u][v], dis[u][i] + dis[i][v]);
    }
        

    for (int i = 1; i <= q; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        long long ans = 1e18;
        for (int j = 0; j < (int) sub[u].size(); ++j)
            for (int k = 0; k < (int) sub[v].size(); ++k) 
            ans = min( 1ll * sub[u][j].dis + 1ll * sub[v][k].dis + dis[ sub[u][j].id ][ sub[v][k].id ], ans );
        printf("%lld\n", ans + w[u] + w[v]);
    }
}
