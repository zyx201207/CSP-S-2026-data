#include<bits/stdc++.h>
#define For(i,s,t) for(int i=(s);i<=(t);++i)
#define Down(i,s,t) for(int i=(s);i>=(t);--i)
#define inf 0x3f3f3f3f
#define Inf (1ll<<60)
#define eps 1e-6
#define ls (i<<1)
#define rs (i<<1|1)
#define Debug(format,...) fprintf(stderr,format,##__VA_ARGS__)
#define ep emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
char *p1,*p2,buf[1<<20];
#define gc() (p1==p2 ? (p2=buf+fread(p1=buf,1,1<<20,stdin),p1==p2 ? EOF : *p1++) : *p1++)
inline int read(){
    int x=0,f=1;
    char c=gc();
    while(c<'0' || c>'9') f=(c=='-' ? -1 : 1),c=gc();
    while('0'<=c && c<='9') x=(x<<3)+(x<<1)+(c&15),c=gc();
    return x*f;
}
inline int max(int x,int y){return x>y ? x : y;}
inline ll max(ll x,ll y){return x>y ? x : y;}
inline int min(int x,int y){return x<y ? x : y;}
inline ll min(ll x,ll y){return x<y ? x : y;}
inline void ckmx(int &x,int y){x=(x<y ?  y : x);}
inline void ckmx(ll &x,ll y){x=(x<y ? y : x);}
inline void ckmn(int &x,int y){x=(x>y ? y : x);}
inline void ckmn(ll &x,ll y){x=(x>y ? y : x);}
const int N=4050;
int n,m,f[N][N],g[N][N],h[N],t[N],sz[N],dfn[N],dfu,dis[N][N],dep[N];
vector<int> tr[N];
void dfs(int u,int fa){
    h[u]=sz[u]=1,dfn[u]=++dfu;
    For(i,0,n) f[u][i]=inf;
    f[u][1]=0;
    for(int v : tr[u])
        if(v!=fa){
            dfs(v,u);
            ckmx(h[u],h[v]+1);
            For(i,0,sz[u]) t[i]=inf;
            For(i,1,sz[u])
                For(j,0,sz[v])
                    ckmn(t[i+j],max(f[u][i],f[v][j]));
            sz[u]+=sz[v];
            For(i,1,sz[u]) f[u][i]=t[i];
        }
    f[u][0]=h[u],f[u][sz[u]]=0;
}
void dfs1(int u,int fa){
    for(int v : tr[u])
        if(v!=fa)
            dep[v]=dep[u]+1,dfs1(v,u);
}
bool vis[N];
int q[N],head,tail;
void solve(){
    n=read(),m=read();
    For(i,1,n) tr[i].clear();
    int u,v;
    For(i,2,n) u=read(),v=read(),tr[u].ep(v),tr[v].ep(u);
    dfu=0;
    dfs(1,0);
    For(i,1,n)
        For(j,i,n){
            For(k,1,n) vis[k]=0;
            head=1,tail=0;
            q[++tail]=i;
            if(head==tail) q[++tail]=j;
            dep[i]=dep[j]=0;
            while(head<=tail){
                int u=q[head];++head;
                vis[u]=1;
                for(int v : tr[u]){
                    if(vis[v]) continue;
                    dep[v]=dep[u]+1;
                    q[++tail]=v;
                }
            }
            For(k,1,n){
                if(dfn[i]<=dfn[k] && dfn[k]<dfn[i]+sz[i]) continue;
                if(dfn[j]<=dfn[k] && dfn[k]<dfn[j]+sz[j]) continue;
                ckmx(dis[i][j],dep[k]);
            }
        }
    int ans=inf;
    For(u,1,n)
        For(v,u+1,n)
            For(s,max(1,m-sz[v]),min(sz[u],m-1))
                ckmn(ans,max({f[u][s],f[v][m-s],dis[u][v]}));
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read();
    int T=read();
    while(T--) solve();
    return 0;
}