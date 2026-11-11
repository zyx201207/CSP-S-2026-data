#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,t,c,ans,mn[N],vis[N],vis2[N];vector<int>g[N],pre;
void dfs(int u,int fa,int cnt){
    if(mn[u]<cnt) return;
    mn[u]=cnt;
    for(int v:g[u])
        if(v!=fa)
            dfs(v,u,cnt+1);
}
void dfs2(int u){
    vis[u]=1;
    for(int v:g[u])
        if(!vis[v]&&vis2[v])
            dfs2(v);
}
bool check2(){
    int cnt=0;memset(vis,0,sizeof(vis));
    for(int i:pre)
        if(!vis[i])
            cnt++,dfs2(i);
            return cnt<=2;
}
void dfs1(int x,int cnt){
    if(cnt==m){
        memset(mn,0x3f,sizeof(mn));
        if(!check2()) return;
        for(int i:pre) dfs(i,0,0);
        ans=min(ans,*max_element(mn+1,mn+1+n));
        return;
    }
    if(x==n+1) return;
    pre.push_back(x);vis2[x]=1;dfs1(x+1,cnt+1);pre.pop_back();vis2[x]=0;
    dfs1(x+1,cnt);
}
bool check(){
    int k=(n-1)/2;
    for(int i=1;i<=n;i++)
        for(int j:g[i])
            if(j>i&&j!=i+1&&j!=i+m+1)
                return 0;
    return 1;
}
signed main(){
    
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;ans=1e9;
        for(int i=1,x,y;i<n;i++)
            cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
        if(check()) {
            cout<<(n-m+1)/2<<'\n';
            continue;
        }
        dfs1(1,0);cout<<ans<<'\n';
    }
    return 0;
}
