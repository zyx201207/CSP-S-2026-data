#include<bits/stdc++.h>
#define OpenFile(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define CloseFile fclose(stdin),fclose(stdout)
#define getchar getchar_unlocked
#define rep(x,y,z) for(int x=(y);x<=(z);++x)
#define per(x,y,z) for(int x=(y);x>=(z);--x)
#define N 100005
using namespace std;
int get(int ans=0,int x=1){
    char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')x=-1;ch=getchar();}
    while(ch>=48&&ch<=57)ans=(ans<<1)+(ans<<3)+ch-48,ch=getchar();
    return ans*x;
}int c,t,dep[N],n,k,p[N][20];
vector<int>g[N];
void dfs(int u,int f){
    dep[u]=dep[f]+1,p[u][0]=f;
    rep(i,1,19)p[u][i]=p[p[u][i-1]][i-1];
    for(auto&v:g[u])if(v!=f)dfs(v,u);
}int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    per(i,19,0)if(dep[p[u][i]]>=dep[v])u=p[u][i];
    if(u==v)return u;
    per(i,19,0)if(p[u][i]!=p[v][i])u=p[u][i],v=p[v][i];
    return u;
}int dist(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
void solve(){
    n=get(),k=get();
    rep(i,1,n)g[i].clear();
    rep(i,2,n){
        int u=get(),v=get();
        g[u].emplace_back(v);
    }dfs(1,0);
    int ans=INT_MAX;
    rep(i,1,n)rep(j,i+1,n){
        int tmp=0;
        rep(k,1,n)tmp=max(tmp,min(dist(k,i),dist(k,j)));
        ans=min(ans,tmp);
    }printf("%d\n",ans);
}signed main(){
    OpenFile(hub);
    c=get(),t=get();
    rep(i,1,t)solve();
    CloseFile;
    return 0;
}
