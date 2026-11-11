#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
typedef long long ll;
const int N = 2e5+5,M=21;
int d[550][550],tt[N],fa[N];
int findd(int x){
    return fa[x] == x?x:fa[x] = findd(fa[x]);
}
struct pth
{
    int u,v,w;
    friend bool operator<(pth a,pth b){
        return a.w < b.w;
    }
}p[N];
struct Edge{
    int to,nxt,val;
}e[N<<2];
int head[N],Ecnt;
void add(int u,int v,int w){
    e[++Ecnt] = {v,head[u],w};
    head[u]=Ecnt;
}


bool vis[N];
int dis[N];
void dij(int s){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s] = 0;
    priority_queue<pii> q;
    q.push({0,s});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].val;
            if(dis[v] > dis[u] + w) {
                dis[v]=dis[u] + w;
                if(!vis[v]) q.push({-dis[v],v});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T,n,m,dd,q;
    cin>>T>>m>>n>>dd>>q;
    for(int i=1;i<=n;i++){
        cin>>tt[i];fa[i] = i;
    }
    if(T<=6){
        memset(d,0x3f,sizeof d);
        
        for(int i=1;i<=m;i++){
            int k;cin>>k;
            for(int j=1;j<=k;j++){
                int v,w;
                cin>>v>>w;
                d[n+i][v] = d[v][n+i] = min(d[n+i][v],w);
            }
        }
        for(int k = 1;k<=n+m;k++){
            for(int x = 1;x<=n+m;x++){
                for(int y =1;y<=n+m;y++){
                    d[x][y] = min(d[x][y],d[x][k]+d[y][k]);
                }
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<tt[x] + tt[y] + d[x][y]<<'\n';
        }
    }
    if(T>=7 && T<=11){
        for(int i=1;i<=m;i++){
            int k,u1,u2,v1,v2;
            cin>>k;
            if(k==1)continue;
            cin>>u1>>v1>>u2>>v2;
            add(u1,u2,v1+v2);
            add(u2,u1,v1+v2);
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            dij(x);
            cout<<tt[x] + tt[y] + d[y]<<'\n';
        }
    }
    return 0;
}//24-32pts