#include<bits/stdc++.h>
using namespace std;
const int N=505,INF=1e9;
int c,n,m,d,q;
vector<int> w(N),k(N);
vector<vector<pair<int,int>>> adj(N);
vector<vector<pair<int,int>>> lines(N);
vector<int> dist(N,INF);
void dj(int x,int y){
    fill(dist.begin(),dist.end(),INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[x]=0;
    pq.push({0,x});
    while(!pq.empty()){
        int u=pq.top().second,d=pq.top().first;
        pq.pop();
        if(dist[u]<d){
            continue;
        }
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first,w=adj[u][i].second;
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({d+w,v});
            }
        }
    }

}
}
signed main(){
    reopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int kk=k[i];
        while(kk--){
            int a,b;
            cin>>a>>b;
            lines[i].push_back({a,b});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k[i];j++){
            int u=lines[i][j].first,ud=lines[i][j].second;
            for(int jj=j+1;jj<k[i];jj++){
                int v=lines[i][jj].first,vd=lines[i][jj].second;
                adj[u].push_back({v,ud+vd});
                adj[v].push_back({u,ud+vd});
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        dj(x,y);
        cout<<dist[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
