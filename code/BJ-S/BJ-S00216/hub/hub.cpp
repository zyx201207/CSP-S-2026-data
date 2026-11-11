#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,lyc;
vector<int>g[2001000];
int bfs(int s){
    int vis[n+1];
    for(int i=1;i<=n;i++){
        vis[i]=-1;
    }
    vis[s]=0;
    queue<int>q;
    q.push(s);
    while(q.size()){
        int f=q.front();q.pop();
        for(int p:g[f]){
            if(vis[p]+1!=0)continue;
            vis[p]=vis[f]+1;
            if(lyc&(1<<p-1))return vis[p];
            q.push(p);
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>c>>t;
    int ans=1000000000;
    while(t--){
        ans=100000000;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<(1<<n);i++){
            lyc=i;
            int cnt=0;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0)cnt++;
            }
            if(cnt!=k)continue;
            int res=0;
            for(int j=1;j<=n;j++){
                if(i&(1<<j-1))continue;
                res=max(res,bfs(j));
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
