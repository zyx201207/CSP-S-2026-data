#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int C,T,n,m,s[N][23],dfn[N],idx,d[N],ans;bool f[N],vis[N];
vector<int> e[N];
int get(int x,int y){return dfn[x]<dfn[y]?x:y;}
int popcount(int x){
    int res=0;
    while(x){
        x-=(x&(-x));
        res++;
    }
    return res;
}
void dfs(int x){
    vis[x]=1;
    for(int i:e[x]){
        if(vis[i]||(!f[i]))continue;
        dfs(i);
    }
}
void Dfs(int x,int fa){
    dfn[x]=++idx;
    s[dfn[x]][0]=fa;
    for(int i:e[x]){
        if(i==fa)continue;
        d[i]=d[x]+1;
        Dfs(i,x);
    }
}
int lca(int u,int v){
    if(u==v)return u;
    u=dfn[u];v=dfn[v];
    if(u>v)swap(u,v);
    int k=__lg(v-u++);
    return get(s[u][k],s[v-(1<<k)+1][k]);
}
void solve(){
    idx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    Dfs(1,0);
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            s[i][j]=get(s[i][j-1],s[i+(1<<(j-1))][j-1]);
        }
    }
    ans=n+1;
    for(int i=0;i<(1<<n);i++){
        if(popcount(i)!=m)continue;
        for(int j=1;j<=n;j++)f[j]=vis[j]=0;
        for(int j=1;j<=n;j++){
            if(i&(1<<(j-1))){
                f[j]=1;
                // cout<<j<<" ";
            }
        }
        // cout<<": ";
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(f[j]&&(!vis[j])){
                dfs(j);
                cnt++;
                if(cnt>2)break;
            }
        }
        if(cnt>2)continue;
        int res=0;
        for(int j=1;j<=n;j++){
            int tmp=n+1;
            for(int k=1;k<=n;k++){
                if(!f[k])continue;
                // cout<<j<<" "<<k<<" "<<lca(j,k)<<"\n";
                tmp=min(tmp,d[j]+d[k]-2*d[lca(j,k)]);
            }
            res=max(res,tmp);
        }
        ans=min(ans,res);
        // cout<<res<<"\n";
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--)solve();
    return 0;
}