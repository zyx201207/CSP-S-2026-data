#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500100];
struct lyc{
    int a,b;
    bool operator<(const lyc o)const{
        return b>o.b;
    }
}willspendhistime;
vector<lyc>g[500100],e[510];
int dis[600][600];
void dij(int s){
    priority_queue<lyc>pq;
    dis[s][s]=0;
    bool vis[n+1]={0};
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    pq.push({s,0});
    while(pq.size()){
        lyc f=pq.top();pq.pop();
        if(vis[f.a])continue;
        vis[f.a]=1;
        for(lyc p:e[f.a]){
            if(dis[s][p.a]>dis[s][f.a]+p.b){
                dis[s][p.a]=dis[s][f.a]+p.b;
                pq.push({p.a,dis[s][f.a]+p.b});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1000000000010101010;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,b;
            cin>>a>>b;
            g[a].push_back({i,b});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto p:g[i]){
            for(auto q:g[i]){
                if(p.a==q.a)continue;
                e[p.a].push_back({q.a,q.b+p.b});
                e[q.a].push_back({p.a,p.b+q.b});
            }
        }
    }
    for(int i=1;i<=n;i++){
        dij(i);
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int res=1000010001000000000;
        for(lyc p:g[u]){
            for(lyc q:g[v]){
                res=min(res,p.b+q.b+dis[p.a][q.a]);
            }
        }
        cout<<res+w[u]+w[v]<<'\n';
    }
    cout<<endl;
    return 0;
}

