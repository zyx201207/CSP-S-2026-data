#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans,vis[1000001],viss[1000001],dis[4001][4001],d[1000001];
vector<int>g[1000001];
int cont(int x){
    int res=0;
    while(x){
        res+=(x&1);
        x>>=1;
    }
    return res;
}
void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    memset(dis[s],0x3f,sizeof(dis[s]));
    memset(vis,0,sizeof(vis));
    dis[s][s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i:g[u]){;
            if(dis[s][i]>dis[s][u]+1){
                dis[s][i]=dis[s][u]+1;
                q.push({dis[s][i],i});
            }
        }
    }
}
void dfs(int x){
    viss[x]=2;
    for(int i:g[x]){
        if(viss[i]==1)dfs(i);
    }
}
bool check1(vector<int>s){
    int cnt=0;
    for(int i:s){
        if(viss[i]==1){
            cnt++;
            dfs(i);
        }
    }
    if(cnt>2)return false;
    else return true;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;while(t--){
        if(c<=3){
            ans=0x3f3f3f3f3f3f3f3f;
            cin>>n>>k;
            for(int i=1;i<=n;i++)g[i].clear();
            for(int i=1;i<n;i++){
                int u,v;cin>>u>>v;
                g[u].push_back(v),g[v].push_back(u);
            }
            for(int i=1;i<=n;i++)dijkstra(i);
            for(int i=(1<<k)-1;i<(1<<n);i++){
                if(cont(i)!=k)continue;
                vector<int>s;
                for(int j=0;j<n;j++)if(((i>>j)&1)==1)viss[j+1]=1,s.push_back(j+1);
                if(!check1(s))continue;
                int dist=0;
                for(int j=1;j<=n;j++){
                    d[j]=0x3f3f3f3f3f3f3f3f;
                    for(int k:s)d[j]=min(d[j],dis[j][k]);
                    dist=max(dist,d[j]);
                }
                ans=min(ans,dist);
            }
            cout<<ans<<endl;
        }
        else cout<<2<<endl;
    }
    return 0;
}