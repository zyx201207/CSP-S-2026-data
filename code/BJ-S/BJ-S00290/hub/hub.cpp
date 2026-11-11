#include<bits/stdc++.h>
using namespace std;
const int N=12;
int c,t,ans,g[N],n,k,dis[N];
bool vis[N];
vector<int> G[N];
int bfs(int x){
    queue<int> q;
    q.push(x);
    for(int i=1;i<=n;i++)dis[i]=1e9;
    dis[x]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:G[u]){
            if(dis[v]!=1e9)continue;
            q.push(v);
            dis[v]=dis[u]+1;
        }
    }
    int mn=1e9;
    for(int i=1;i<=n;i++){
        if(g[i])mn=min(mn,dis[i]);
    }
    return mn;
}
void dfs(int x){
    vis[x]=1;
    for(auto v:G[x]){
        if(!vis[v]&&g[v])dfs(v);
    }
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(int i=0;i<(1<<n);i++){
            int cnt=0,r=i,now=0;
            for(int j=1;j<=n;j++){
                g[j]=r%2;
                r/=2;
                cnt+=g[j];
            }
            if(cnt!=k)continue;
            cnt=0;
            for(int j=1;j<=n;j++)vis[j]=0;
            for(int j=1;j<=n;j++){
                if(g[j]&&!vis[j]){
                    cnt++;
                    dfs(j);
                }
            }
            if(cnt>2)continue;
            for(int j=1;j<=n;j++){
                now=max(now,bfs(j));
            }
            ans=min(ans,now);
        }
        cout<<ans<<endl;
    }
    return 0;
}
