#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
const int N=1e5+5;
using namespace std;
int t,n,k,c,dis[N];
vector<int> e[N];
queue<int> q;
bool vis[N],ves[N];
void dfs(int u){
    int len=e[u].size();
    for(int i=0;i<len;i++){
        int v=e[u][i];
        if(vis[v]&&!ves[v])ves[v]=1,dfs(v);
    }return;
}
void bfs(){
    while(!q.empty()){
        int u=q.front();q.pop();
        int len=e[u].size();
        for(int i=0;i<len;i++){
            int v=e[u][i];
            if(!vis[v])dis[v]=dis[u]+1,q.push(v),vis[v]=1;
        }
    }return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }int ans=n+1;
        for(int i=0;i<(1<<n);i++){
            int sum=0;for(int i=1;i<=n;i++)vis[i]=ves[i]=0;
            for(int j=0;j<n;j++)if(i&(1<<j))vis[j+1]=1,sum++;
            if(sum!=k)continue;sum=0;
            for(int i=1;i<=n;i++)if(vis[i]&&!ves[i])dfs(i),sum++;
            if(sum>2)continue;sum=0;
//            for(int i=1;i<=n;i++)cout<<vis[i]<<" ";cout<<"\n";
            for(int i=1;i<=n;i++)if(vis[i])q.push(i);
            for(int i=1;i<=n;i++)dis[i]=0;bfs();
            for(int i=1;i<=n;i++)sum=max(sum,dis[i]);
//            for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<"\n";
            ans=min(ans,sum);
            }cout<<ans<<"\n";

    }
    return 0;
}
