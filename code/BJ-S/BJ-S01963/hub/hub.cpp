#include <iostream>
#include <vector>
using namespace std;
const int N=2e6+5;
int cid,T,n,k,ct,mxx,sz[N],dp[N],dep[N];
vector<int>E[N];
void cent(int u,int fa){
    sz[u]=1;
    int mx=0;
    for(int v:E[u]){
        if(v==fa)continue;
        cent(v,u);
        sz[u]+=sz[v];
        mx=max(mx,sz[v]);
    }
    mx=max(mx,n-sz[u]);
    if(mx<mxx){
        ct=u;
        mxx=mx;
    }
}
void dfs(int u,int fa){
    sz[u]=dp[u]=0;
    for(int v:E[u]){
        if(v==fa)continue;
        dfs(v,u);
        sz[u]+=sz[v];
        dp[u]=max(dp[u],dp[v]+1);
    }
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        E[i].clear();
        dp[i]=0;
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    mxx=n;
    cent(1,0);
    //cout<<ct<<endl;
    dep[ct]=0;
    dfs(ct,0);
    cout<<dp[ct]-1<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>cid>>T;
    while(T--)solve();
}
