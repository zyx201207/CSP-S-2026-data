#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int M = 5e5 + 1, N = 501, INF = 1e9 + 1;

int c, n, m, d, q;
int w[M];
struct Edge{
    int v, w;
};
vector<Edge> adj[N + M];

namespace S1{
    bool vis[N + M];
    int dist[N + M];
    struct Node{
        int u, dis;
        bool operator <(const Node &i) const{
            return dis > i.dis;
        }
    };
    void dijkstra(int s){
        fill(vis, vis + 1 + m + n, 0);
        fill(dist, dist + 1 + m + n, INF);
        priority_queue<Node> pq;
        pq.push({s, 0});
        dist[s] = 0;
        while(!pq.empty()){
            auto now = pq.top();
            pq.pop();
            int u = now.u, dis = now.dis;
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto edge : adj[u]){
                int v = edge.v, w = edge.w;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
                }
            }
        }
    }
    void Solve(){
         int x, y;
         while(q--){
            cin >> x >> y;
            dijkstra(x + n);
            cout << dist[y + n] + w[x] + w[y] << '\n';
         }
    }
}

namespace Sp1{
    const int Sp1_M = 1001;
    int dist[Sp1_M];
    bool vis[Sp1_M][Sp1_M];
    void dfs(int u, int f){
        for(auto edge : adj[u]){
            int v = edge.v, w = edge.w;
            if(v == f) continue;
            dist[u] = dist[f] + w;
            dfs(v, u);
        }
    }
    void Solve(){
        int x, y;
        while(q--){
            cin >> x >> y;
            fill(dist + 1, dist + 1 + m + n, INF);
            dfs(x, x);
            cout << dist[y + n] + w[x] + w[y] << '\n';
        }
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1, k; i <= n; i++){
        cin >> k;
        for(int j = 1, a, t; j <= k; j++){
            cin >> a >> t;
            adj[i].push_back({n + a, t});
            adj[n + a].push_back({i, t});
        }
    }
    if(c <= 6) S1::Solve();
    else Sp1::Solve();
    return 0;
}
