#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<ll, ll> >g[500005];

ll n, m, d, c, q, dis[505][505], k;
ll w[500005];
int main(){
    freopen("subway.in" , "r", stdin );
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            int x, y;
            cin >> x >> y;
            //a[i].push_back(x);
            //b[i].push_back(y);
            g[x].push_back({i, y});
        }
    }
    for(int i = 0; i <= 501; i++){
        for(int j = 0; j <= 501; j++){
            if(i != j) dis[i][j] = 1e18;
        }
    }
    for(int i = 1; i <= m; i++){
        int num = g[i].size();
        for(int j = 0; j < num; j++){
            dis[j][j] = 0;
            for(int k = 0; k < j; k++){
                int nd1 = g[i][j].first;
                int nd2 = g[i][k].first;
                dis[nd1][nd2] = min(dis[nd1][nd2], g[i][j].second+g[i][k].second);
            }
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                dis[i][j] = min(dis[i][k]+dis[k][j], dis[i][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = dis[j][i];
        }
    }
    while(q--){
        ll ans = 1e18;
        int u, v;
        cin >> u >> v;
        if(u == v){
            cout << 0 << endl;
        }else{
            for(int i = 0; i < g[u].size(); i++){
                for(int j = 0; j < g[v].size(); j++){
                    int nd1 = g[u][i].first;
                    int nd2 = g[v][j].first;
                    ans = min(ans, dis[nd1][nd2]+g[u][i].second+g[v][j].second);
                }
            }
            cout << ans+w[u]+w[v] << endl;
        }
    }
    return 0;
}
