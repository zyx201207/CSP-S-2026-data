#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 505;
#define ll long long
int n, m, C, D, Q;
int x[N+M], mp[M];
ll d[M][M];
pair<int, int> g[N][21];
int gt[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> C >> m >> n >> D >> Q;
    for (int i = 1; i <= n; i+=1) cin >> x[i];
    for (int i = 1; i <= m; i+=1){
        for (int j = 1; j <= m; j+=1) d[i][j] = 1e18;
        d[i][i] = 0;
        int ks; cin >> ks;
        for (int j = 1; j <= ks; j+=1){
            int to, p;
            cin >> to >> p;
            g[to][++gt[to]] = {i, p};
        }
    }
    for (int i = 1; i <= n; i+=1){
        for (int j = 1; j <= gt[i]; j+=1){
            for (int k = j+1; k <= gt[i]; k+=1){
                int u = g[i][j].first, v = g[i][k].first;
                int wu = g[i][j].second, wv = g[i][k].second;
                d[u][v] = min(d[u][v], (ll)wu+wv);
                d[v][u] = d[u][v];
            }
        }
    }
    for (int k = 1; k <= m; k+=1){
        for (int i = 1; i <= m; i+=1){
            for (int j = 1; j <= m; j+=1){
                d[i][j] = min(d[i][k]+d[k][j], d[i][j]);
            }
        }
    }
    for (int i = 1; i <= Q; i+=1){
        int st, ed;
        cin >> st >> ed;
        ll res = 1e18;
        for (int j = 1; j <= m; j+=1) mp[j] = 0;
        for (int j = 1; j <= gt[st]; j+=1){
            for (int k = 1; k <= gt[ed]; k+=1){
                res = min(res, d[g[st][j].first][g[ed][k].first]+g[st][j].second+g[ed][k].second);
            }
        }
        cout << res+x[st]+x[ed] << '\n';
    }
    return 0;
}
