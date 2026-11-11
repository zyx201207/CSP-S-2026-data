#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,n,m,d,q,w[N];
int head[N],idx,dis[505][N/2+10000];
queue<pair<int,int>> pq;
struct Edge{int nex,v,w;}edge[N<<1];
void add(int u,int v,int w){
    edge[++idx]={head[u],v,w},head[u]=idx;
}
void SPFA(int s){
    memset(dis[s-m],0x3f,sizeof dis[s-m]);
    dis[s-m][s]=0;
    pq.emplace(0,s);
    while(!pq.empty()){
        int u=pq.front().second;
        pq.pop();
        for(int i=head[u];i!=-1;i=edge[i].nex){
            int v=edge[i].v,w=edge[i].w;
            if(dis[s-m][u]+w<dis[s-m][v]){
                dis[s-m][v]=dis[s-m][u]+w;
                pq.emplace(-dis[s-m][v],v);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    memset(head,-1,sizeof head);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            add(i+m,x,y),add(x,i+m,y);
        }
    }
    for(int i=1;i<=n;i++){
        SPFA(i+m);
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int ans=0x3f3f3f3f3f3f3f3f;
        for(int i=head[u];i!=-1;i=edge[i].nex){
            int q=edge[i].v;
            ans=min(ans,dis[q-m][u]+dis[q-m][v]+w[u]+w[v]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
