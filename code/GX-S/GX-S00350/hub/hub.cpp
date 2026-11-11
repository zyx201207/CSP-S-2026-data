#include <bits/stdc++.h>
using namespace std;
namespace solve{
    bool choose[15];
    int n,k;
    vector<int> T[15];
    int ans=INT_MAX;
    bool vis[15];
    void bfs(int s){
        queue<int> q;
        q.push(s);
        vis[s]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:T[u]){
                if(vis[v]||!choose[v]) continue;
                q.push(v);
                vis[v]=1;
            }
        }
    }
    int bfs2(int s){
        bool viss[15];
        int dist[15]={};
        viss[s]=1;
        queue<int> q;
        q.push(s);
        dist[s]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:T[u]){
                if(vis[v]) continue;
                dist[v]=dist[u]+1;
                if(choose[v]) return dist[v];
                q.push(v);
                vis[v]=1;
            }
        }
        int ret=INT_MAX;
        for(int i=1;i<=n;i++) if(choose[i]) ret=min(ret,dist[i]);
        return ret;
    }
    int check(){
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(choose[i]&&!vis[i]){
                if(cnt==2) return INT_MAX;
                bfs(i);
                cnt++;
            }
        }
        int ret=0;
        for(int i=1;i<=n;i++){
            if(!choose[i]){
                ret=max(ret,bfs2(i));
            }
        }
        return ret;
    }
    void dfs(int dep){
        if(dep==n+1){
            int cnt=0;
            for(int i=1;i<=n;i++) cnt+=choose[i];
            if(cnt!=k) return;
            ans=min(ans,check());
            return;
        }else{
            choose[dep]=0;
            dfs(dep+1);
            choose[dep]=1;
            dfs(dep+1);
        }
    }
    void sol(){
        cin >>n >>k;
        for(int i=1;i<=n;i++) T[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin >>u >>v;
            T[u].push_back(v);
            T[v].push_back(u);
        }
        dfs(1);
        cout <<ans <<endl;
    }
};
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >>c >>t;
    while(t--){
        solve::sol();
    }
    return 0;
}
