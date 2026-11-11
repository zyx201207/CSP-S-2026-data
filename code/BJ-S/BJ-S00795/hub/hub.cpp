#include<iostream>
#include<vector>
#define int long long
using namespace std;
const int N = 1e6 + 10,inf = 4e18;
int n,k,vis[N + 1];
vector<int> g[N + 1];
void dfs(int u,int f,int mask){
    vis[u] = true;
    for(int v : g[u])
        if(v != f && (mask & (1 << (v - 1))))
            dfs(v,u,mask);
}
int dfs2(int u,int f,int mask,int d){
    if(mask & (1 << (u - 1)))
        return d;
    int res = inf;
    for(int v : g[u])
        if(v != f)
            res = min(dfs2(v,u,mask,d + 1),res);
    return res;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) g[i].clear();
        for(int i = 1;i <= n - 1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = inf;
        for(int i = 0;i < (1 << n);i++){
            int cnt = 0;
            for(int j = 1;j <= n;j++)
                if(i & (1 << (j - 1))) cnt++;
            if(cnt != k) continue;
            cnt = 0;
            for(int j = 1;j <= n;j++) vis[j] = false;
            for(int j = 1;j <= n;j++)
                if((i & (1 << (j - 1))) && vis[j] == false){
                    cnt++;
                    dfs(j,0,i);
                }
            if(cnt > 2) continue;
            cnt = 0;
            for(int j = 1;j <= n;j++)
                cnt = max(cnt,dfs2(j,0,i,0));
            ans = min(ans,cnt);
        }
        cout<<ans<<"\n";
    }
}
