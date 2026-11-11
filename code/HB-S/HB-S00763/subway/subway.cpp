#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=507,M=5e5+7,oo=2e18;

int c,n,m,d,q,ans,cnt;
int w[M],k[N];
int dis[N][80000],vis[N+M];
int dist[5][M+N];
int head[N+M];

struct edge{
    int nxt,to,w;
}e[M*2+N*2];
void add(int x,int y,int w){
    e[++cnt]=(edge){head[x],y,w};
    head[x]=cnt;
}

struct node{
    int u,dis;
    bool operator < (const node &x)const{return dis>x.dis;}
};
void dij(int s,int (&dis)[80000]){
    priority_queue<node>q;
    for(int i=1;i<=m+n;i++){
        dis[i]=oo;
        vis[i]=0;
    }
    dis[s]=0;
    q.push((node){s,0});
    while(!q.empty()){
        node p=q.top();q.pop();
        int u=p.u;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push((node){v,dis[v]});
            }
        }
    }
}
void dij2(int s,int (&dis)[M+N]){
    priority_queue<node>q;
    for(int i=1;i<=m+n;i++){
        dis[i]=oo;
        vis[i]=0;
    }
    dis[s]=0;
    q.push((node){s,0});
    while(!q.empty()){
        node p=q.top();q.pop();
        int u=p.u;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push((node){v,dis[v]});
            }
        }
    }
}
int solve1(int x,int y){
    int ans=oo;
    for(int i=1;i<=n;i++){
        ans=min(ans,dis[i][x]+dis[i][y]);
    }
    return ans+w[x]+w[y];
}
void compute1(){
    for(int i=1;i<=n;i++){
        dij(m+i,dis[i]); 
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        cout<<solve1(x,y)<<"\n";
    }
}
int solve2(int x,int y){
    int ans=oo;
    for(int i=1;i<=n;i++){
        ans=min(ans,dist[i][x]+dist[i][y]);
    }
    return ans+w[x]+w[y];
}
void compute2(){
    for(int i=1;i<=n;i++){
        dij2(m+i,dist[i]); 
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        cout<<solve2(x,y)<<"\n";
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,a,t;j<=k[i];j++){
            cin>>a>>t;
            add(m+i,a,t);
            add(a,m+i,t);
        }
    }
    if(c<=19)compute1();
    else compute2();
    return 0;
}