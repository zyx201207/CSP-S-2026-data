#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6 + 5, inf = 0x3f3f3f3f;
int c, n, k;
vector<int> g[NR];
bool vis[NR];
int dis[NR];

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; i ++) g[i].clear();
}

void dfs(int x, int mask){
    vis[x] = 1;
    for(int y : g[x]){
        if(vis[y] || (mask&(1<<y-1) == 0)) continue;
        dfs(y, mask);
    }
}

bool check(int mask){
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if((mask&(1<<i-1) == 0)) continue;
        if(!vis[i]){
            //cout << i << "// ";
            cnt ++;
            dfs(i, mask);
            if(cnt > 2) return 0;
        }
    }
    //cout << endl;
    return 1;
}

void dfs2(int x, int mask){
    for(int y : g[x]){
        if(dis[y] < inf || vis[y]) continue;
        dis[y] = min(dis[y], dis[x] + 1);
        dfs2(y, mask);
    }
}

void solve()
{
    cin >> n >> k;
    for(int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0x3f3f3f3f;
    for(int mask = 0; mask < (1<<n); mask ++){
        if(__builtin_popcount(mask) != k) continue;
        memset(vis, 0 ,sizeof(vis));
        if(!check(mask)) continue;
        for(int i = 1; i <= n; i ++){
            if(vis[i]) {
                //cout << i <<  "// ";
                dis[i] = 0, dfs2(i, mask);
            }
        }
        cout << endl;
        int sum = 0;
        for(int i = 1; i <= n; i ++){
            sum = max(sum, dis[i]);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    init();
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T;
    cin >> c >> T;
    while(T --){
        solve();
    }
    return 0;
}
/**
0 1
5 2
1 2
2 3
3 4
4 5

**/
