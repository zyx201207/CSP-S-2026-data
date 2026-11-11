#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define fst first
#define snd second

using namespace std;

const int NR = 510;
const int MR = 5e5 + 10;
int n, m, D, q;
int W[MR];
vector<pii> g[NR]; // (a, t_a)
int k[NR];
vector<pii> gd[MR];
ll dis[NR][NR];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int _;
    scanf("%d%d%d%d%d", &_, &n, &m, &D, &q);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &W[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        g[i].resize(k[i] + 3);
        for(int j = 1; j <= k[i]; j++) {
            scanf("%d%d", &g[i][j].fst, &g[i][j].snd);
            gd[g[i][j].fst].push_back({i, g[i][j].snd});
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; i++) dis[i][i] = 0;

    /*
    for(int i = 1; i <= m; i++) {
        printf("! %d: ", i);
        for(int j = 0; j < gd[i].size(); j++) {
            printf("(%d,%d) ", gd[i][j].fst, gd[i][j].snd);
        }
        puts("");
    }
    */

    for(int i = 1; i <= m; i++) {
        for(int j0 = 0; j0 < gd[i].size(); j0++) {
            for(int j = 0; j < gd[i].size(); j++) {
                pii itu = gd[i][j0], itv = gd[i][j];
                int u = itu.fst, v = itv.fst;
                //printf("@ %d %d\n", u, v);
                dis[u][v] = min(dis[u][v], 1ll * itu.snd + itv.snd);
            }
        }
    }
    for(int kk = 1; kk <= n; kk++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][kk] + dis[kk][j]);
            }
        }
    }

    /*
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%lld ", dis[i][j]);
        }
        puts("");
    }
    */

    while(q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = 9e18;
        for(pii itu : gd[x]) {
            for(pii itv : gd[y]) {
                //printf("$ (%d,%d) (%d,%d)\n", itu.fst, itu.snd, itv.fst, itv.snd);
                ans = min(ans, 1ll * W[x] + W[y] + dis[itu.fst][itv.fst] + itu.snd + itv.snd);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
