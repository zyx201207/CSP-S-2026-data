#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 5e5 + 5;
const ll inf = 1e14;
struct Edge{
    int pos, to, val;
};
vector<Edge> g[maxn * 22];
//entrance-i, hall-i+m, platform-p+2*m
int c, n, m, d, q;
int lst[505];
struct Node{
    int pos;
    ll val;
    bool operator< (const Node& other) const{
        return val > other.val;
    }
};
priority_queue<Node> pq;
Node dis[maxn * 22];
bool vis[maxn * 22];
ll ans = 0;

void Dijkstra(int s, int t){
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<maxn*22;i++) dis[i].pos = i, dis[i].val = inf;
    while(pq.size()) pq.pop();
    dis[s].val = 0;
    pq.push(dis[s]);
    while(!pq.empty()){
        Node node = pq.top();
        pq.pop();
        int u = node.pos;
        ll val = node.val;
        if(vis[u]) continue;
        vis[u] = 1;
        int s = g[u].size();
        for(int i=0;i<s;i++){
            int v = g[u][i].to, w = g[u][i].val;
            if(vis[v]) continue;
            if(val + w < dis[v].val){
                dis[v].val = val + w;
                if(v == t){
                    ans = dis[v].val;
                    return ;
                }
                pq.push(dis[v]);
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    int w;
    for(int i=1;i<=m;i++){
        cin >> w;
        g[i].push_back({i, i+m, w});
        g[i+m].push_back({i+m, i, w});
    }
    int k, a, t;
    int tot = 2 * m;
    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> a >> t;
            int u = ++tot;
            if(lst[i]){
                g[u].push_back({u, lst[i], 0});
                g[lst[i]].push_back({lst[i], u, 0});
            }
            lst[i] = u;
            g[a+m].push_back({a+m, u, t});
            g[u].push_back({u, a+m, t});
        }
    }
    int u, v;
    while(q--){
        cin >> u >> v;
        Dijkstra(u, v);
        cout << ans << '\n';
    }

    return 0;
}
