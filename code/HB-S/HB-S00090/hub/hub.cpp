#include <bits/stdc++.h>
#define int long long
using namespace std;

int T,c,n,k,vis[505],dis[505][505],use[505],INF=0x3f3f3f3f3f3f3f3f,ans=1e18;

vector<int> g[505],path;

void bfs(int s){
    int flag[505]={};
    for(int j:path) flag[j]=1;

    queue<int> q;
    q.push(s);
    vis[s]=1;

    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(!flag[v] || vis[v]) continue;
            vis[v]=1;
            q.push(v);
        }
    }
}

bool check(){
    memset(vis,0,sizeof(vis));

    int cnt=0;
    for(int u:path){
        if(!vis[u]){
            cnt++;
            bfs(u);
        }
    }

    return cnt<=2;
}

void dfs(int dep,int cnt){
    if(cnt==k){
        if(!check()) return;
        // for(int j:path) cerr << j << ' ';
        // cerr << '\n';
        int maxd=-1e18;
        for(int i=1;i<=n;i++){
            int d=1e18;
            for(int j:path) d=min(d,dis[i][j]);
            maxd=max(maxd,d);
        }
        ans=min(ans,maxd);
        return;
    }
    if(dep==n+1) return;

    path.push_back(dep);
    dfs(dep+1,cnt+1);
    path.pop_back();

    dfs(dep+1,cnt);
}

void BFS(int s){
    memset(use,0,sizeof(use));
    queue<int> q,d;
    q.push(s);
    d.push(0);
    use[s]=1;

    while(!q.empty()){
        int u=q.front(),len=d.front(); q.pop();
        dis[s][u]=d.front(); d.pop();
        for(int v:g[u]){
            if(use[v]) continue;
            use[v]=1;
            d.push(len+1);
            q.push(v);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin >> c >> T;
    while(T--){
        ans=1e18;
        cin >> n >> k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;i++) BFS(i);

        dfs(1,0);

        cout << ans << '\n';
    }
    return 0;
}
//g++ -o hub hub.cpp -O2 -std=c++14 -static