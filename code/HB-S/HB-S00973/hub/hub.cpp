#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e6+5,M=105;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int cid,T,n,k,h[N],etot;
struct edge{
    int nxt,to;
}e[N*2];

void adde(int u,int v){
    e[++etot].nxt=h[u];
    h[u]=etot;
    e[etot].to=v;
}

namespace ssolve1{
    int f[M],d[M],len[M],xx;
    void dfs(int u,int fa){
        f[u]=fa;d[u]=d[fa]+1;len[u]=1;
        for(int i=h[u],v;i;i=e[i].nxt){
            v=e[i].to;if(v==fa)continue;
            dfs(v,u);if(v!=xx)len[u]=max(len[u],len[v]+1);
        }
    }

    int work(int x){
        int ans=0,dd=d[x];
        x=f[x];
        while(f[x]){
            ans=max(ans,min(dd-d[x],d[x]-1)+len[x]-1);
            x=f[x];
        }
        return ans;
    }
}

namespace solve1{
    int f[M][M],g[M],siz[M],len[M],d[M],ff[M],rt;

    void dfs1(int u,int fa){
        ff[u]=fa;
        siz[u]=1;len[u]=1;f[u][0]=1;f[u][1]=0;d[u]=d[fa]+1;
        for(int i=h[u],v;i;i=e[i].nxt){
            v=e[i].to;if(v==fa)continue;
            dfs1(v,u);
            for(int j=0;j<=siz[u]+siz[v];++j)g[j]=n;
            for(int j=1;j<=siz[u];++j){
                for(int k=1;k<=siz[v];++k){
                    g[j+k]=min(g[j+k],max(f[u][j],f[v][k]));
                }
                g[j]=min(g[j],max(f[u][j],len[v]));
            }
            siz[u]+=siz[v];len[u]=max(len[u],len[v]+1);
            for(int i=1;i<=siz[u];++i){
                f[u][i]=g[i];
            }
            f[u][0]=len[u];
        }
        // cout<<" u:"<<u<<" f:";
        // for(int i=0;i<=k;++i)cout<<f[u][i]<<" ";cout<<endl;
    }

    int getfa(int x){
        if(ff[x]==rt)return x;
        return getfa(ff[x]);
    }

    void solve(){
        int ans=n;
        for(int i=1;i<=n;++i){
            dfs1(i,0);rt=i;
            ans=min(ans,f[i][k]);
            for(int x=1;x<=n;++x){
                for(int y=1;y<=n;++y){
                    if(x==y||x==i||y==i)continue;
                    if(getfa(x)==getfa(y))continue;
                    int an=n;
                    for(int j=1;j<k;++j){
                        an=min(an,max(f[x][j],f[y][k-j]));
                    }
                    ssolve1::xx=y;
                    ssolve1::dfs(x,0);
                    an=max(an,ssolve1::work(y));
                    ans=min(an,ans);
                }
            }
        }
        print(ans);putchar('\n');
    }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cid=read();T=read();
    while(T--){
        n=read();k=read();etot=0;
        for(int i=1;i<=n;++i)h[i]=0;
        for(int i=1;i<n;++i){
            int u=read(),v=read();
            adde(u,v);adde(v,u);
        }
        if(cid==13||cid==14){
            int ans;
            n/=2;
            if(n*2+1==k)ans=0;
            else ans=(n-k)/4+(((n-k)%4)!=0)+1;
            print(ans);putchar('\n');
        }
        else solve1::solve();
    }
    return 0;
}