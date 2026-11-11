#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500001], f[501][501];
struct edge{
    int p, val;
    edge(int P, int VAL){
        p = P;
        val = VAL;
    }
};
vector<edge>g[500001];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q, k, x, y;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)scanf("%lld", w + i);
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++){
        f[i][i] = 0;
        cin >> k;
        while(k--){
            scanf("%lld%lld", &x, &y);
            g[x].push_back(edge(i, y));
        }
    }
    for(int i = 1; i <= m; i++){
        k = g[i].size();
        for(int a = 0; a < k; a++){
            for(int b = a + 1; b < k; b++){
                x = g[i][a].p;
                y = g[i][b].p;
                f[x][y] = f[y][x] = min(f[x][y], g[i][a].val + g[i][b].val);
            }
        }
    }
    for(int l = 1; l <= n; l++)for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)f[i][j] = min(f[i][j], f[i][l] + f[l][j]);
    while(q--){
        cin >> x >> y;
        k = 0x7f7f7f7f7f7f7f7fll;
        for(int i = 0; i < g[x].size(); i++)for(int j = 0; j < g[y].size(); j++)k = min(k, f[g[x][i].p][g[y][j].p] + g[x][i].val + g[y][j].val);
        cout << k + w[x] + w[y] + 1 << "\n";
    }
    return 0;
}

