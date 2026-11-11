#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ull unsigned long long
#define eb emplace_back
#define umap unordered_map
#define ll long long
#define Fast1 ios::sync_with_stdio(0)
#define Fast2 cin.tie(0),cout.tie(0)
#define int long long
#define pk pop_back
//首先遇到这种题目我们先把直径拿出来
//然后如果是 1 个连通块的情况考虑怎么做
//发现如果一个点在直径中点上一定不劣
//然后让直径的中点作为树根容易发现
// 2 边均匀分配一定是不劣的
//然后考虑如果是 2 个连通块的时候怎么做
//手玩一些东西我们猜测一定有 2 个点
const int N=1e6+5;
vector<int>e[N];
int dep[N],mxdep[N];
int n,k,c;
void dfs(int u,int f){
    mxdep[u]=dep[u]=dep[f]+1;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];if(v==f)continue;
        dfs(v,u);mxdep[u]=max(mxdep[u],mxdep[v]);
    }
}vector<int>node;int f_=0;
void dfs2(int tar,int u,int f){
    node.pb(u);
    if(u==tar){f_=1;return;}
    if(f_==1)return;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];if(v==f)continue;
        dfs2(tar,v,u);if(f_)return;
    }node.pk();
}
void _(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].pb(v);e[v].pb(u);
    }if(c<=3){

    }
    dfs(1,0);int mx=-1e18,id=-1;
    for(int i=1;i<=n;i++)if(dep[i]>=mx)mx=dep[i],id=i;
    dfs(id,0);int ans=1e18;int id_=id;mx=-1e18,id=-1;
    for(int i=1;i<=n;i++)if(dep[i]>=mx)mx=dep[i],id=i;
    int cnt=0;
    for(int i=1;i<=n;i++)if(dep[i]==mx)cnt++;
    ans=min(ans,(mx+1)/2);dfs2(id_,id,0);
    if(cnt>1){cout<<ans<<"\n";return;}
    int rt=0;
    for(int i=0;i<node.size();i++){
        int c=node[i];
        if(c==(mx+1)/2-1)rt=c;
    }dfs(rt,0);int mx2=-1e18;
    for(int i=0;i<e[rt].size();i++){
        int v=e[rt][i];
        if(mxdep[v]==mx)continue;
        mx2=max(mx2,mxdep[v]);
    }cout<<(mx+mx2)/3<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    Fast1;Fast2;int t=1;
    cin>>c>>t;
    while(t--)_();
}
