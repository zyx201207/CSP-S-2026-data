#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define ll long long

using namespace std;

const int N = 505, M = 1e3+5;
ll c, n, m, d, q, x, y, w[M], k[N];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ll sta[N][M], tim[N][M];
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++){
        cin>>w[i];
    }
    for(int i=1; i<=n; i++){
        cin>>k[i];
        for(int j=1; j<=k[i]; j++){
            cin>>sta[i][j]>>tim[i][j];
        }
    }

    vector<pair<ll, ll> > edge[M];
    for(int i=1; i<=n; i++){
        for(int j=1; j<k[i]; j++){
            for(int l=j+1; l<=k[i]; l++){
                edge[sta[i][j]].push_back({sta[i][l], tim[i][j]+tim[i][l]});
                edge[sta[i][l]].push_back({sta[i][j], tim[i][j]+tim[i][l]});
            }
        }
    }

    ll dis[M], vis[M];
    while(q--){
        cin>>x>>y;
        priority_queue<pair<ll, ll>,
            vector<pair<ll, ll> >,
           greater<pair<ll, ll> > > pq;
        memset(dis, 0x7f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[x] = 0;
        pq.push({0, x});
        while(!pq.empty()){
            pair<ll, ll> u = pq.top();
            pq.pop();
            if(vis[u.second]) continue;
            vis[u.second] = 1;
            for(int i=0; i<edge[u.second].size(); i++){
                ll to = edge[u.second][i].first, w = edge[u.second][i].second;
                if(dis[to]>dis[u.second]+w){
                    dis[to] = dis[u.second]+w;
                    pq.push({dis[to], to});
                }
            }
        }
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
