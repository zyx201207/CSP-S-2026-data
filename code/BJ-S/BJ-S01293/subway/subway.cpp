#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int c,n,m,d,q,ans=1e9;
long long w[20005];
long long dis[20005];
vector<pii> g[20005];
int toway[20005][505];
vector<int> stowy[505];
bool vis[20005];
void dijkstra(int u){
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({0,u});
    dis[u]=0;
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        int tu=t.second,tw=t.first;
        if(vis[tu])continue;
        vis[tu]=1;
        for(auto v:g[tu]){
            int wv=v.first,uv=v.second;
            if(dis[uv]>dis[tu]+wv){
                dis[uv]=dis[tu]+wv;
                q.push({dis[uv],uv});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int tx;
        cin>>tx;
        for(int j=1;j<=tx;j++){
            int x;
            cin>>x>>toway[x][i];
            stowy[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<stowy[i].size();j++){
            for(int k=j+1;k<stowy[i].size();k++){
                int u=stowy[i][j],v=stowy[i][k];
                int w=toway[u][i]+toway[v][i];
                g[u].push_back({w,v});
                g[v].push_back({w,u});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int st,ed;
        cin>>st>>ed;
        dijkstra(st);
        cout<<dis[ed]+w[st]+w[ed]<<'\n';
    }
    return 0;
}
