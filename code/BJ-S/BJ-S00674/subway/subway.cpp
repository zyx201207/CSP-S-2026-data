#include<bits/stdc++.h>
#define ll long long
#define PII pair<long long,int>
using namespace std;
int c,n,m,d,q;
int w[500010];
vector<PII>g[501010];
bool vis[500010];
ll dist[500010];
void solve(){
    int x,y;
    cin >> x >>y;
    for(int i = 1;i <= m +n; i++){
        dist[i] = 1e18;
        vis[i] = 0;
    }
    priority_queue<PII,vector<PII>,greater<PII> >pq;
    dist[x] =0;
    pq.push({0,x});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(PII e :g[u]){
            int v = e.first;
            if(dist[v] > dist[u] + e.second){
                dist[v] = dist[u] + e.second;
                vis[v] = 0;
                pq.push({dist[v],v});
            }
        }
    }
    cout << dist[y] + w[x] + w[y] << '\n';
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n; i++){
        int k;
        cin >> k;
        int u = 0,v,t;
        for(int j = 1;j <= k; j++){
            cin >> v >> t;
            g[m+i].push_back({v,t});
            g[v].push_back({m+i,t});
            if(u != 0){
               // g[u].push_back({v,0});
            }
            u = v;
        }
    }
    while(q--){
        solve();
    }
    return 0;
}
