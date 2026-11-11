#include <cstdio>
#include <vector>
using namespace std;
struct edge{
    int u;
    long long w;
};
long long min(long long a, long long b){
    return a < b ? a : b;
}
int c, n, m, d, q, k[505];
long long w[500005], dp[505][505];
vector<edge> g[500005];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++){
        scanf("%lld", &w[i]);
    }
    int u, s, su, ss;
    long long wt;
    for(int i = 0; i < n; i++){
        scanf("%d", &k[i]);
        for(int j = 0; j < k[i]; j++){
            scanf("%d %lld", &u, &wt);
            g[u].push_back(edge{i, wt});
        }
        for(int j = 0; j < n; j++){
            dp[i][j] = 1000000000000000ll;
        }
        dp[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        s = g[i].size();
        for(int j = 0; j < s; j++){
            for(int l = j + 1; l < s; l++){
                dp[g[i][j].u][g[i][l].u] = min(dp[g[i][j].u][g[i][l].u], g[i][j].w + g[i][l].w);
                dp[g[i][l].u][g[i][j].u] = min(dp[g[i][l].u][g[i][j].u], g[i][j].w + g[i][l].w);
            }
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

            }
        }
    }
    while(q--){
        scanf("%d %d", &u, &s);
        wt = 1000000000000000ll;
        su = g[u].size(), ss = g[s].size();
        for(int i = 0; i < su; i++){
            for(int j = 0; j < ss; j++){
                wt = min(wt, w[u] + g[u][i].w + dp[g[u][i].u][g[s][j].u] + g[s][j].w + w[s]);
            }
        }
        printf("%lld\n", wt);
    }
    return 0;
}
