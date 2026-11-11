#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int nn = 5e5 + 5, mm = 505;
ll dp[mm][mm], a[nn];
vector<pair<int, int>> e[nn];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    scanf("%d %d %d %d %d", &c , &m, &n, &d, &q);
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(int i = 1; i <= m; ++i){
        dp[i][i] = 0;
        int k, x, y;
        scanf("%d", &k);
        for(int j = 1; j <= k; ++j){
            scanf("%d %d", &x, &y);
            e[x].emplace_back(make_pair(i, y));
        }
    }
    for(int i = 1; i <= n; ++i){
        int len = e[i].size();
        for(int j = 0; j < len; ++j)
            for(int k = j + 1; k < len; ++k){
                int u = e[i][j].first, v = e[i][k].first;
                ll w = e[i][j].second + e[i][k].second;
                dp[u][v] = dp[v][u] = min(dp[u][v], w);
            }
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= m; ++j){
            for(int k = 1; k <= m; ++k){
                dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);
            }
        }
    }
    while(q--){
        int u, v;
        scanf("%d %d", &u, &v);
        ll ans = 9e18;
        for(pair<int, int> i : e[u]) for(pair<int, int> j : e[v]) ans = min(ans, dp[i.first][j.first] + i.second + j.second);
        printf("%lld\n", ans + a[u] + a[v]);
    }
    return 0;
}