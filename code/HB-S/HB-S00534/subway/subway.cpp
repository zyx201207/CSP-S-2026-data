#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=505,M=5e5+5,INF=INT_MAX;
int c,n,m,d,q,w[M],a[N][M],t[N][M],ans;
bool vis[M];
struct ed{
    int v,w,num;
};
vector<ed> G[N];
inline void dfs(int u,int v,int en,int dis,int nu){
    if(dis>ans||vis[v]){
        return ;
    }
    vis[v]=1;
    if(v==en){
        ans=min(ans,dis+t[nu][v]);
        return ;
    }
    for(ed nxt:G[v]){
        if(u==0)dfs(v,nxt.v,en,dis+nxt.w,nxt.num);
        else{
            if(nxt.num==nu){
                dfs(v,nxt.v,en,dis,nxt.num);
            }
            else{
                dfs(v,nxt.v,en,dis+t[nu][v]+nxt.w,nxt.num);
            }
        }
    }
    vis[v]=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][a[i][j]];
        }
        for(int j=2;j<=k;j++){
            G[a[i][j]].push_back({a[i][j-1],t[i][a[i][j]],i});
            G[a[i][j-1]].push_back({a[i][j],t[i][a[i][j-1]],i});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        for(int j=1;j<=m;j++){vis[j]=0;};
        ans=INF;
        dfs(0,x,y,w[x]+w[y],0);
        cout<<ans<<endl;
    }
    return 0;
}
