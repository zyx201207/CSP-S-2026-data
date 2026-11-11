#include<bits/stdc++.h>
using namespace std;
namespace fastIO{
    const int IN_BUF=1<<20;
    char inbuf[IN_BUF],*p1=inbuf,*p2=inbuf;
    inline int gc(){
        if(p1==p2){
            p2=(p1=inbuf)+fread(inbuf,1,IN_BUF,stdin);
            if(p1==p2) return EOF;
        }
        return *p1++;
    }
    inline int read(){
        int k=0,f=1;
        int c=gc();
        while(c!=EOF&&!isdigit(c)){
            if(c=='-') f=-1;
            c=gc();
        }
        if(c==EOF) return 0;
        while(c!=EOF&&isdigit(c)){
            k=(k<<1)+(k<<3)+(c^48);
            c=gc();
        }
        return k*f;
    }
    const int OUT_BUF=1<<22;
    char outbuf[OUT_BUF],*now=outbuf;
    inline void pc(char c){
        if(now-outbuf==OUT_BUF){
            fwrite(outbuf,1,OUT_BUF,stdout);
            now=outbuf;
        }
        *now++=c;
    }
    inline void write(int x){
        if(x==0){
            pc('0');
            return ;
        }
        if(x<0){
            x=-x;
            pc('-');
        }
        char s[25];
        int len=0;
        while(x){
            s[len++]=x%10+'0';
            x/=10;
        }
        while(len--) pc(s[len]);
    }
    inline void flush(){
        fwrite(outbuf,1,now-outbuf,stdout);
        now=outbuf;
    }
}
using namespace fastIO;
const int N=2e6+5;
int c,t,n,k;
vector<int> g[N];
bool cs[N];
int dfn[N],cnt;
int d[N];
int dep[N],f[N][20];
inline void dfs(int u,int fa){
    dfn[u]=++cnt;
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int v:g[u]){
        if(v==fa) continue ;
        dfs(v,u);
    }
}
inline int getlca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=19;i>=0;i--){
        if(dep[f[u][i]]>=dep[v]){
            u=f[u][i];
        }
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];
}
inline int getdis(int u,int v){
    int lca=getlca(u,v);
    return dep[u]-dep[lca]+dep[v]-dep[lca];
}
bool vis[N];
inline void find(int u,int fa){
    vis[u]=1;
    for(int v:g[u]){
        if(v==fa||!cs[v]) continue ;
        find(v,u);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();t=read();
    while(t--){
        int ans=1e9;
        n=read();k=read();
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++) cs[i]=0;
        cnt=0;
        for(int i=1;i<=n;i++){
            dfn[i]=0;
            dep[i]=0;
            for(int j=0;j<20;j++){
                f[i][j]=0;
            }
        }
        dfs(1,0);
        for(int j=1;j<20;j++){
            for(int i=1;i<=n;i++){
                f[i][j]=f[f[i][j-1]][j-1];
            }
        }
        for(int s=0;s<(1<<n);s++){
            int num=0;
            for(int i=1;i<=n;i++){
                if(s&(1<<(i-1))){
                    cs[i]=1;
                    num++;
                }else{
                    cs[i]=0;
                }
            }
            if(num!=k) continue ;
            for(int i=1;i<=n;i++) vis[i]=0;
            int lt=0;
            for(int i=1;i<=n;i++){
                if(cs[i]&&!vis[i]){
                    find(i,0);
                    lt++;
                }
            }
            if(lt>2) continue ;
            for(int i=1;i<=n;i++){
                d[i]=1e9;
            }
            for(int i=1;i<=n;i++){
                if(cs[i]){
                    d[i]=0;
                    continue ;
                }
                for(int j=1;j<=n;j++){
                    if(!cs[j]||i==j) continue ;
                    d[i]=min(d[i],getdis(i,j));
                }
            }
            int mx=0;
            for(int i=1;i<=n;i++){
                mx=max(mx,d[i]);
            }
            ans=min(ans,mx);
        }
        write(ans);
        pc('\n');
    }
    flush();
    return 0;
}
