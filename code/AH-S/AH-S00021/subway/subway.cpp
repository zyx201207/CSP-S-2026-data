#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 2, M = 2e2 + 2;
int dist[N][M], n, c, m, d, q, w[N], tot, vis[N][M];
vector<pair<int, int>> e[N];
void dijkstra(int x){
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) dist[i][j] = 2e17;
    for(int i = 1; i <= n; i++){
            if(vis[x][i] > 0){
                dist[x][i] = vis[x][i];
                pq.push({vis[x][i], x, i});
            }
    }
    while(!pq.empty()){
        auto [w, x, y] = pq.top();
        pq.pop();
        for(auto [u, z] : e[x]){
            int d = w;
            if(z != y) d += vis[x][z] + vis[u][z];
            else d += vis[u][z];
            if(dist[u][z] > d) dist[u][z] = d, pq.push({d, u, z});
        }  
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];    
    for(int i = 1; i <= n; i++){
            int k;
            cin >> k;
            int lst = 0;
            for(int j = 1, x, t; j <= k; j++){
                cin >> x >> t;
                if(lst == 0) lst = x;
                else{ 
                e[lst].push_back({x, i});
                e[x].push_back({lst, i});
                lst = x;
            }
                vis[x][i] = t;
                
            }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        dijkstra(x);
        int ans = 2e17;
        for(int i = 1; i <= n; i++) ans = min(dist[y][i], ans);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
