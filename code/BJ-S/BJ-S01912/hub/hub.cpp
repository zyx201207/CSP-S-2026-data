#include <bits/stdc++.h>
using namespace std;
const int N = 13;
int n, k, x, y, dis[N][N];
vector<int> g[N];
bool c[N], vis[N];
void dfs(int x){
    if (!c[x] || vis[x]) return;
    vis[x] = 1;
    for (auto i : g[x]) dfs(i);
}
void solve(){
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1;i <= n;i++){
        dis[i][i] = 0;
        g[i].clear();
    }
    cin >> n >> k;
    for (int i = 1;i < n;i++){
        cin >> x >> y;
        dis[x][y] = dis[y][x] = 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int ans = 2e9;
    for (int i = 0;i < (1 << n);i++){
        for (int j = 0;j < n;j++)
            c[j + 1] = i & (1 << j);
        int t = 0;
        for (int j = 1;j <= n;j++) t += c[j];
        if (t != k) continue;
        memset(vis, 0, sizeof(vis));
        t = 0;
        for (int j = 1;j <= n;j++){
            if (c[j] && !vis[j]){
                t++;
                dfs(j);
            }
        }
        if (t > 2) continue;
        t = 0;
        for (int x = 1;x <= n;x++){
            if (c[x]) continue;
            int mn = 2e9;
            for (int j = 1;j <= n;j++)
                if (c[j]) mn = min(mn, dis[x][j]);
            t = max(t, mn);
        }
        ans = min(ans, t);
    }
    cout << ans << endl;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) solve();
}
