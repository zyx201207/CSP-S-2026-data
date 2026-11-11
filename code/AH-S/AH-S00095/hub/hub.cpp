#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
using ll=__int128;
ll read(){
    ll f=1,x=0;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-')f=1-f;
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^48);
        cc=getchar();
    }while(isdigit(cc));
    return(f?x:-x);
}
vector<int>g[1000005];
bitset<1000005>vis;
bitset<1000005>vs;
int n,k,rs;
void flood(int u,int fa){
    vs[u]=1;
    for(int v:g[u]){
        if(v!=fa&&vis[u]){
            flood(v,u);
        }
    }
}
bool check(){
    if(vis.count()!=k)return 0;
    vs.reset();
    int cnt=0;
    fo(i,1,n){
        if(vis[i]&&!vs[i]){
            ++cnt;
            if(cnt>1)return 0;
            flood(i,i);
        }
    }
    return 1;
}
int dfs1(int u,int fa){
    int len=0;
    for(int v:g[u]){
        if(v!=fa&&vis[v]){
            int tmp=dfs1(v,u);
            rs=max(rs,len+tmp);
            len=max(len,tmp);
        }
    }
    return len;
}
int calc(){
    rs=0;
    for(int i=1;i<=n;++i){
        if(vis[i]){
            dfs1(i,i);
            return rs;
        }
    }
}
int dfs(int idx,int cnt){
    if(idx>n){
        return check()?calc():0x3f3f3f3f;
    }
    if(cnt+n-idx+1<k)return 0x3f3f3f3f;
    int ans=dfs(idx+1,cnt);
    vis[idx]=1;
    return max(ans,dfs(idx+1,cnt+1));
}
void solve(){
    vis.reset();
    fill(g+1,g+1000000+1,vector<int>());
    n=read();
    k=read();
    fo(i,1,n-1){
        int u=read(),v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(k==2){
        puts("1");
        return;
    }else printf("%d",dfs(1,0));
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read(),T=read();
    do{
        solve();
    }while(--T);
    return 0;
}
