#include<bits/stdc++.h>
using namespace std;
using lld=long long;
const int N=5005;
lld W[N];
struct node{
    int v,tv;
    lld w;
};
struct nc3{
    lld w;
    int u,tu;
};
vector<node> g[N];
lld t[N][N];
lld dis[N][N];
bool vis[N];
lld lst[N][N];
void dij(int s){
    priority_queue<tuple<lld,int,int>> q;
    q.push({0,s,-1});
    while(q.size()){
        auto o=q.top();
        int u=get<1>(o);
        int tu=get<2>(o);
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(node e:g[u]){
            lld w;
            int v=e.v,tv=e.tv;
            if(tu==tv){
                dis[s][v]=dis[s][u];
                q.push({-dis[s][v],v,tv});
                lst[s][v]=t[tv][v];
            }
            else{
                w=t[tu][v]+t[tv][v];
                if(dis[s][v]>dis[s][u]+w){
                    dis[s][v]=dis[s][u]+w;
                    q.push({-dis[s][v],v,tv});
                    lst[s][v]=t[tv][v];
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    lld c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>W[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<int> a(k+1);
        for(int j=1;j<=k;j++){
            cin>>a[j];
            cin>>t[i][a[j]];//i这条线到站j的站台
        }
        for(int j=2;j<=k;j++){
            g[a[j]].push_back({a[j-1],i,0});
            g[a[j-1]].push_back({a[j],i,0});
        }
    }
    for(int u=1;u<=m;u++){
        for(int v=1;v<=m;v++){
            dis[u][v]=1e18;
            vis[v]=0;
        }
        dis[u][u]=0;
        dij(u);
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<dis[u][v]<<' ';
        cout<<dis[u][v]+W[u]+W[v]<<'\n';
    }
    return 0;
}