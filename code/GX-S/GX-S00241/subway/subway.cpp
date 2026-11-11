#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(a) \
(freopen(#a".in", "r", stdin),\
freopen(#a".out", "w", stdout))
const int N = 505, M = 2e4+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[M];
vector<pair<int, int>> g[M+N];

struct node{
    int u;
    ll dis;
    bool operator<(const node &o)const{
        return o.dis < dis;
    }
}; priority_queue<node> p;
ll dis[M+N];
bool vis[M+N];
void dijkstra(int s){
    for(int i = 1; i <= m+n; ++i)
        dis[i] = inf, vis[i] = false;
    p.push({s, dis[s] = 0});
    while(!p.empty()){
        const int u = p.top().u;
        p.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(const auto &i : g[u]){
            const int &v = i.first, &w = i.second;
            if(dis[u] + w < dis[v])
                p.push({v, dis[v] = dis[u] + w});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    file(subway);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        while(k--){
            int a, t;
            cin >> a >> t;
            g[a].push_back({m+i, t});
            g[m+i].push_back({a, t});
        }
    }
    while(q--){
        int s, t;
        cin >> s >> t;
        dijkstra(s);
        cout << w[s] + dis[t] + w[t] << '\n';
    }
    return 0;
}
