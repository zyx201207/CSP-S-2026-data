#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int c,n,m,d,q,w[N],tot,vis[N],dis[N];
vector<pair<int,int>> e[N];
int bfs(int s,int t){
    priority_queue<pair<int,int>> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(u==t) return dis[u];
        if(vis[u]) continue;
        vis[u]=1;
        for(auto i:e[u]){
            int v=i.first,w=i.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
    return -1;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    tot=m;
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,id,x;j<=k;j++){
            cin>>id>>x;
            tot++;
            if(j!=1){
                e[tot-1].push_back({tot,0});
                e[tot].push_back({tot-1,0});
            }
            e[id].push_back({tot,x});
            e[tot].push_back({id,x});
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<bfs(x,y)+w[x]+w[y]<<endl;
    }
    return 0;
}
