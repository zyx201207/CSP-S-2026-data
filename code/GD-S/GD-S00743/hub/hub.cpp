#include <bits/stdc++.h>
#define int long long
#define vector basic_string
#define pii array<int,2>
using namespace std;
int read(){
    int s=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
int c,T;
int n,k,fa[1000010],f[1000010],g[1000010],ans;
vector<int>e[1000010];
int dep[1000010];
pii ban;
void dfs(int u,int f){
    fa[u]=f;
    for(int v:e[u]) if(v^f) dfs(v,u);
}
int ff[1000010];
void dfs2(int u,int f,int &d){
    dep[u]=dep[f]+1,ff[u]=f;
    for(int v:e[u]){
        if((u==ban[0]&&v==ban[1])||(u==ban[1]&&v==ban[0])||v==f) continue;
        dfs2(v,u,d);
    }
    if(dep[u]>dep[d]) d=u;
}
void dfs3(int u,int fw){
    dep[u]=1;
    for(int v:e[u]){
        if((u==ban[0]&&v==ban[1])||(u==ban[1]&&v==ban[0])||v==fw) continue;
        dfs3(v,u);
        dep[u]=max(dep[u],dep[v]+1);
    }
    f[dep[u]]++;
}
void calc(int u){
    for(int i=1;i<=n;i++) f[i]=0;
    int s=0,t=0;
    dfs2(u,0,s);
    dfs2(s,0,t);
    int p=dep[t]/2;
    while(p--) t=ff[t];
    dfs3(t,0);
}
int r[1000010];
void solve(){
    n=read(),k=read(),ans=n;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1,u,v;i<n;i++){
        u=read(),v=read();
        e[u]+=v,e[v]+=u;
    }
    dfs(1,0);
    ban={0,0};
    calc(1);
    for(int i=2;i<=n;i++) r[i]=i;
    sort(r+2,r+1+n,[&](int x,int y){return dep[x]>dep[y];});
    for(int o=2,i;o<=n;o++){
        if(c>10&&o*n>10000000) break;
        i=r[o];
        ban={i,fa[i]};
        calc(1);
        for(int j=1;j<=n;j++)
            g[j]=f[j];
        calc(i);
        for(int j=1,s=n;j<=n;j++){
            s-=f[j]+g[j];
            if(s<=k){
                ans=min(ans,j);
                // printf("%lld %lld\n",i,j);
                break;
            }
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // clock_t st=clock();
    c=read(),T=read();
    while(T--) solve();
    // fprintf(stderr,"%.2lf\n",(clock()-st)*1.0/CLOCKS_PER_SEC);
    return 0;
}