#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,m;
vector<int> g[110];
int check(int k){
    int vis[20];
    int cnt=0;
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        if(!vis[i]&&(k&(1<<(i-1)))){
            cnt++;
            if(cnt>2)return 1e9;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                vis[u]=cnt;
                for(int j=0;j<(int)g[u].size();j++){
                    if(vis[g[u][j]]||!(k&(1<<(g[u][j]-1))))continue;
                    q.push(g[u][j]);
                }
            }
        }
    }
    int res=0;
    int dis[10][10];
    memset(dis,0,sizeof dis);
    for(int i=1;i<=n;i++){
        if(k&(1<<(i-1))||vis[i])continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int j=0;j<(int)g[u].size();j++){
                if(vis[g[u][j]])continue;
                dis[i][g[u][j]]=dis[i][u]+1;
                res=max(res,dis[i][g[u][j]]);
                q.push(g[u][j]);
            }
        }
    }
    return res+1;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        if(n==m){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=1e9;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount((unsigned)i)==m)ans=min(ans,check(i));
        }
        cout<<ans<<'\n';
    }
    return 0;
}
