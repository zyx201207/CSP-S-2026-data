#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int add2(int x,int y){
    add(x,y);
    return x;
}
int qpow(int a,ll b){
    int mul=1;
    for(;b;b>>=1,a=(ll)a*a%MOD) if(b&1) mul=(ll)mul*a%MOD;
    return mul;
}
const int N=4005;
int n,k,sz[N],fa[N][25],tot=0,dfn[N],dep[N],mxd[N];
vector<pii> es;
vector<int> G[N];
void dfs(int u,int f){
    fa[u][0]=f,dfn[u]=++tot,dep[u]=dep[f]+1,sz[u]=1;
    for(auto v:G[u]){
        if(v==f) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int ans,f[N][N],id[N][N];
void build(int u,int f){
    mxd[u]=0;
    for(auto v:G[u]){
        if(v==f) continue;
        build(v,u);
        chkmax(mxd[u],mxd[v]+1);
    }
}
void calc(int s,int fa,int id){
    // printf("calc %d %d id=%d\n",s,fa,id);
    for(int i=0;i<=n;i++) f[id][i]=inf;
    build(s,fa);
    // for(int i=1;i<=n;i++) printf("%d ",mxd[i]);printf("\n");
    priority_queue<pair<int,pii>> pq;
    pq.push({mxd[s],{s,fa}});
    int c=0;
    while(pq.size()){
        auto [u,fa]=pq.top().second;pq.pop();
        for(auto v:G[u]){
            if(v==fa) continue;
            pq.push({mxd[v],{v,u}});
        }
        if(pq.size()) f[id][++c]=pq.top().first+1;
        else f[id][++c]=0;
    }
    // for(int i=1;i<=n;i++) printf("%d ",f[id][i]);
    // printf("\n");
}
int lca[N][N];
int _lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int i=20;i>=0;i--) if(dep[fa[v][i]]>=dep[u]) v=fa[v][i];
    if(u==v) return u;
    for(int i=20;i>=0;i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
bool anc(int u,int v){return dfn[u]<=dfn[v]&&dfn[v]<dfn[u]+sz[u];}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca[u][v]];}
void __INIT__(){}
void __SOLVE__(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) G[i].clear();
    es.clear();
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v),G[v].push_back(u);
        id[u][v]=es.size(),es.push_back({u,v});
        id[v][u]=es.size(),es.push_back({v,u});
    }
    tot=0,dep[1]=0;
    dfs(1,1);
    for(int i=1;i<=20;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) lca[i][j]=_lca(i,j);
    ans=inf;
    // for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("anc %d %d = %d\n",i,j,anc(i,j));
    for(int i=0;i<es.size();i++){
        auto [u,v]=es[i];
        calc(u,v,i);
        int mx=0;
        for(int i=1;i<=n;i++){
            if(v==fa[u][0]&&!anc(u,i)) chkmax(mx,dis(u,i));
            if(u==fa[v][0]&&anc(v,i)) chkmax(mx,dis(u,i));
        }
        chkmin(ans,max(f[i][k],mx));
    }
    for(int x=1;x<=n;x++){
        for(int y=x+1;y<=n;y++){
            int idx=id[x][fa[x][0]],idy=id[y][fa[y][0]];
            if(anc(x,y)){
                int u;
                for(u=y;fa[u][0]!=x;u=fa[u][0]);
                idx=id[fa[u][0]][u];
            }
            if(anc(y,x)){
                int u;
                for(u=x;fa[u][0]!=y;u=fa[u][0]);
                idy=id[fa[u][0]][u];
            }
            int mx=0,d=dis(x,y);
            for(int i=1;i<=n;i++){
                if(i==x||i==y) continue;
                int dx=dis(i,x),dy=dis(i,y);
                if(abs(dx-dy)==d) continue;
                chkmax(mx,min(dx,dy));
            }
            for(int s=1;s<k;s++){
                // if(max(mx,max(f[idx][s],f[idy][k-s]))==0) printf("%d %d\n",x,y);
                chkmin(ans,max(mx,max(f[idx][s],f[idy][k-s])));
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    #ifndef JZQ
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    #endif
    int T=1;
    scanf("%*d%d",&T);
    __INIT__();
    while(T--) __SOLVE__();
    return 0;
}