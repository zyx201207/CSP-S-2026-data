#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 600, M = 1e6 + 10;

int n, m, d, q;
ll w[M];

struct edge{
    ll u, w;
};
struct node{
    ll u, w;
    bool inline operator < (const node &x) const{
        return x.w < w;
    }
};

vector <edge> trans[M], g[N];
ll resdis[N][N], dis[N][N];

bool vis[N];
void Dij(int s){
    priority_queue <node> q;
    for(int i = 1; i <= n; i ++) vis[i] = 0, dis[s][i] = 1e18;
    dis[s][s] = 0; q.push({s, 0});
    while(!q.empty()){
        auto p = q.top(); q.pop();
        if(vis[p.u]) continue;
        vis[p.u] = 1;
        for(auto i : g[p.u]){
            if(dis[s][i.u] > dis[s][p.u] + i.w){
                dis[s][i.u] = dis[s][p.u] + i.w;
                q.push({i.u, dis[s][i.u]});
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >>c>>n>>m>>d>>q;
    for(int i = 1; i <= m; i ++) cin >>w[i];
    for(int i = 1, k; i <= n; i ++){
        cin >>k;
        for(int j = 1, a, t; j <= k; j ++){
            cin >>a>>t;
            trans[a].push_back({i, t});
        }
    }
    memset(resdis, 0x3f, sizeof(resdis));
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j < trans[i].size(); j ++){
            for(int k = j + 1; k < trans[i].size(); k ++){
                auto u = trans[i][j];
                auto v = trans[i][k];
                resdis[u.u][v.u] = resdis[v.u][u.u] = min(resdis[u.u][v.u], u.w + v.w);
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            if(resdis[i][j] <= 1e10){
                g[i].push_back({j, resdis[i][j]});
                g[j].push_back({i, resdis[j][i]});
            }
        }
    }
    for(int i = 1; i <= n; i ++) Dij(i);

    int x, y;
    ll ans = 0;
    while(q --){
        cin >>x>>y;
        ans = 1e18;
        for(auto i : trans[x]){
            for(auto j : trans[y]){
                ll res = i.w + j.w + dis[i.u][j.u];
                ans = min(ans, res);
            }
        }
        ans += w[x] + w[y];
        cout <<ans<<"\n";
    }

    return 0;
}