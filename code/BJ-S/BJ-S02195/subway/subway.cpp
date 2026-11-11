// Wyh is extremely cute
//I love Wyh
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=5e5+10;
const int maxm=1e5+10;
const int maxk=500+10;
const ll inf=1e18;
int c,m,n,d,q,cnt;
int a[maxn],head[maxn<<1];
ll dis[maxn<<1],ans[maxm];
bool vis[maxn<<1];
struct edge{
    int v,nxt,w;
}e[maxn<<2];
struct query{
    int x,y,op;
}f[maxm];
inline bool cmp(query nx,query ny){return nx.x<ny.x;}
// inline bool cmp2(query nx,query ny){return nx.op<ny.op;}
struct vertex{
    ll ds;
    int op;
    bool operator<(const vertex &nx)const{return ds>nx.ds;}
};
struct view{
    int l,r;
    view(){l=2*maxn,r=-2*maxn;}
}pos[maxn];
vector<pair<int,int> >g[maxk];
priority_queue<vertex>Q;
inline void add(int u,int v,int w){
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
inline void ipt(){
    scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,n+i,y);
            add(n+i,x,y);
            g[i].push_back(make_pair(x,y));
        }
    }
    for(int i=1;i<=q;i++){
        ans[i]=inf;
        scanf("%d%d",&f[i].x,&f[i].y);
        f[i].op=i;
    }
    sort(f+1,f+q+1,cmp);
    for(int i=1;i<=q;i++){
        pos[f[i].x].l=min(pos[f[i].x].l,i);
        pos[f[i].x].r=max(pos[f[i].x].r,i);
    }
    
}
inline void dijkstra(int s){
    while(!Q.empty())Q.pop();
    for(int i=1;i<=n+m;i++)dis[i]=inf,vis[i]=false;
    dis[s]=0;
    Q.push((vertex){dis[s],s});
    while(!Q.empty()){
        int u=Q.top().op;
        Q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(vis[v])continue;
            if(dis[v]>(ll)(dis[u]+e[i].w)){
                dis[v]=(ll)(dis[u]+e[i].w);
                Q.push((vertex){dis[v],v});
            }
        }
    }
}
inline void solve(){
    for(int i=1;i<=m;i++){
        dijkstra(n+i);   
        // if(i==2)printf("")
        for(int j=0;j<g[i].size();j++){
            int u=g[i][j].first,w=g[i][j].second;
            for(int k=pos[u].l;k<=pos[u].r;k++){
                if(ans[f[k].op]>(ll)(dis[f[k].y]+a[f[k].x]+a[f[k].y]+w))ans[f[k].op]=(ll)(dis[f[k].y]+a[f[k].x]+a[f[k].y]+w);
            }
        }
    }      
}
inline void opt(){
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ipt();
    solve();
    opt();
    return 0;
}