#include<bits/stdc++.h>
using namespace std;
const int N=4e3+3;
int testid,T,n,k,dis[N][N],vis[N],tot;
vector<int>adj[N];
inline void getdis(int rt){
    for(int i=1;i<=n;i++)dis[rt][i]=2e9;dis[rt][rt]=0;
    queue<int>q;q.push(rt);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:adj[u]){
            if(dis[rt][v]>dis[rt][u]+1)
                q.push(v),dis[rt][v]=dis[rt][u]+1;
        }
    }
}
inline void dfs(int u,int father){
    bool qwq=0;
    for(auto v:adj[u]){
        if(v==father)continue;
        dfs(v,u),qwq|=vis[v];
    }if(vis[u]&&qwq==0)tot++;
}
inline int calc(){
    int mx=0;
    for(int i=1;i<=n;i++){
        int mn=2e9;for(int j=1;j<=n;j++)
            if(vis[j])mn=min(mn,dis[i][j]);
        mx=max(mx,mn);
    }return mx;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>testid>>T;
    while(T--){
        cin>>n>>k;for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v),adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++)getdis(i);
        int ans=2e9;
        for(int state=0;state<(1<<n);state++){
            int tmp=state,cnt=0;
            for(int i=1;i<=n;i++){
                if(tmp&1)vis[i]=1,cnt++;
                else vis[i]=0;
                tmp>>=1;
            }tot=0,dfs(1,0);
            if(tot<=2&&cnt<=k)ans=min(ans,calc());
        }cout<<ans<<'\n';
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/