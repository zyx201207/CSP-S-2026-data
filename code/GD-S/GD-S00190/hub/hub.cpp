#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define eb emplace_back
using namespace std;

inline int read(){
    char c=getchar();int f=1,x=0;
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}

const int N=1e6+10,mod=998244353;
int c,n,k,fa[N],dep[N],f[N],h[N],F[N],G[N],id[N],X;
vector<int> g[N];
void dfs(int u,int f){
    fa[u]=f,dep[u]=dep[f]+1;
    for(int v:g[u])if(v^f) dfs(v,u);
}
int lca(int x,int y){
    for(;x^y;x=fa[x])if(dep[x]<dep[y]) swap(x,y);
    return x;
}
int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void dfs1(int u,int fa,int rt){
    F[u]=0,f[u]=1;id[u]=rt;::fa[u]=fa;dep[u]=dep[fa]+1;
    for(int v:g[u])if(v^fa){
        dfs1(v,u,!rt?v:rt);
        F[u]=max(F[u],F[v]+1);
        if(F[v]==X) f[u]++;
        if(F[v]>X) f[u]+=f[v];
    }
}
bool ck(int md){
    X=md;
    rep(i,1,n){
        rep(j,1,n) f[j]=F[j]=id[i]=dep[i]=0;
        dfs1(i,0,0);
        rep(j,1,n)if(i^j){
            int v=id[j],s=f[i]+f[j];
            if(F[v]==X) s--;
            if(F[v]>X) s-=f[v];
            if(s<=k){
                int fl=1;
                for(int x=fa[j],y=j;x!=i;y=x,x=fa[x]){
                    int mx=0;
                    for(int v:g[x])if(v!=fa[x]&&v!=y) mx=max(mx,F[v]+1);
                    if(mx+min(dep[j]-dep[x],dep[x]-1)>X){
                        fl=0;
                        break;
                    }
                }
                if(fl) return 1;
            }
        }
    }
    return 0;
}
void Apeiria(){
    rep(i,1,n) g[i].clear(),fa[i]=dep[i]=0;
    n=read(),k=read();
    rep(i,2,n){
        int u=read(),v=read();
        g[u].eb(v);g[v].eb(u);
    }
    dfs(1,0);
    int ans=1e9;
    if(n<=10){
        rep(s,1,(1<<n)-1)if(__builtin_popcount(s)<=k){
            int cnt=__builtin_popcount(s);
            rep(i,1,n)if(s>>i-1&1)
                rep(j,i+1,n)if(s>>j-1&1)
                    if(dis(i,j)==1) cnt--;
            if(cnt<=2){
                int mx=0;
                rep(i,1,n){
                    int mn=1e9;
                    rep(j,1,n)if(s>>j-1&1) mn=min(mn,dis(i,j));
                    mx=max(mx,mn);
                }
                ans=min(ans,mx);
            }
        }
    }
    else{
        int l=1,r=n-1;
        while(r>=l){
            int m=l+r>>1;
            if(ck(m)) r=m-1;
            else l=m+1;
        }
        ans=l;
    }
    printf("%d\n",ans);
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();int T=read();
    rep(i,1,T) Apeiria();
    return 0;
}
