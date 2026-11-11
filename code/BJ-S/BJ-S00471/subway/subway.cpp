#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005], vis[1005][1005];
vector<pair<long long, long long> > g[500005];
int main(){
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++){
        long long k; scanf("%lld", &k);
        while(k--){
            long long a, t; scanf("%lld%lld", &a, &t);
            g[a].push_back(make_pair((long long) i, t));
        }
    } for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(i != j) vis[i][j] = 1E18;
    for(int i = 1; i <= m; i++)
        for(int j = 0; j < g[i].size(); j++)
            for(int k = 0; k < g[i].size(); k++){
                long long x = g[i][j].first, y = g[i][k].first, z = g[i][j].second + g[i][k].second;
                vis[x][y] = min(vis[x][y], z); vis[y][x] = min(vis[y][x], z);
            }
    //for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) printf("%lld %lld %lld\n", i, j, vis[i][j]);
    for(int i = 1; i <= n; i++)
        for(int k = 1; k <= n; k++)
            for(int j = 1; j <= n; j++)
                vis[i][j] = min(vis[i][j], vis[i][k] + vis[k][j]);
    for(int i = 1; i <= q; i++){
        long long x, y, ans = 1E18; scanf("%lld%lld", &x, &y);
        for(int j = 0; j < g[x].size(); j++)
            for(int k = 0; k < g[y].size(); k++){
                long long u = g[x][j].first, v = g[y][k].first, w = g[x][j].second + g[y][k].second;
                ans = min(ans, vis[u][v] + w);
            }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
