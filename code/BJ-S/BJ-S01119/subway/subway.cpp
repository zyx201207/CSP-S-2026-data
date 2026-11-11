#include <bits/stdc++.h>
using namespace std;
const int N=500*25+5,M=1e7+5;
int head[N],tot,vis[N],dist[N];
struct Edge{
    int to,w,nxt;
}e[M];
void add(int u,int v,int w){
    e[++tot]={v,w,head[u]};
    head[u]=tot;
}
void dijkstra(int s){
    memset(dist,0x3f,sizeof dist);
    memset(vis,0,sizeof vis);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        auto[d,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int tc,tn,tm1,td,tq;
int tw[N],tk[M];
int d[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>tc>>tn>>tm1>>td>>tq;
    td++;
    for(int i=1;i<=tm1;i++) cin>>tw[i];
    for(int i=1;i<=tn;i++){
        cin>>tk[i];
        int lst=-1;
        for(int j=1;j<=tk[i];j++){
            int u,v,w;
            cin>>u;
            d[u]++;
            if(lst>0){
                add(td*lst-d[lst],td*u-d[u],0);
                add(td*u-d[u],td*lst-d[lst],0);
            }
            lst=u;
            cin>>w;
            add(td*u,td*u-d[u],w);
            add(td*u-d[u],td*u,w);
        }
    }
    while(tq--){
        int xr,yr;
        cin>>xr>>yr;
        dijkstra(xr*td);
        int ans=dist[yr*td]+tw[xr]+tw[yr];
        cout<<ans<<'\n';
    }

}
//15:27 ac????????
//16:30 da yang li slowly du45pts
