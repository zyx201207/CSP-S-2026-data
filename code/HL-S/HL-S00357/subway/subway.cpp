#include<bits/stdc++.h>
const int maxq = 1e5 + 5;
using namespace std;
int n, m, c, d, q, w[505], k[505], a[505][505], t[505][505], x[maxq], y[maxq], f[505];
vector <int> g[505];
bool vis[505];
struct node {
    int to, w;
    friend bool operator < (node a, node b){
        return a.w > b.w;
    }
};
priority_queue <node> qu;
void dij(int s, int e){
    memset(f, 2e9, sizeof(f));
    qu.push({s, 0}); f[s] = 0;
    while(!qu.empty()){
        node t1 = qu.top(); qu.pop();
        int u = t1.to;if(vis[u]) continue; vis[u] = 1;
        for(int i = 0; i < g[u].size(); i++){
            int ro = g[u][i];
            for(int i = 1; i <= k[ro]; i++){
                if(k[i] == u) continue;
                int v = k[i];
                if(f[v] < f[u] + t[ro][u] + t[ro][v]){
                	f[v] = f[u] + t[ro][u] + t[ro][v];
					qu.push({v, f[v]});
				}
            }
        }
    }
    return;
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> m >> n >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            cin >> a[i][j] >> t[i][a[i][j]];
            g[a[i][j]].push_back(i);
        }
    }
    for(int i = 1; i <= q; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= q; i++){
        dij(x[i], y[i]);
        cout << f[y[i]] + w[x[i]] + w[y[i]]<< '\n';
    }
    return 0;
}
