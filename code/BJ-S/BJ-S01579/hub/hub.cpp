#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a[1000010];
int vis[1000010], vis1[1000010], ans = 1e9;
void dfs1(int x){
    vis1[x] = 1;
    for (int i : a[x]){
        if (!vis1[i]){
            dfs1(i);
        }
    }
}
priority_queue<int> q;
int dis[500010], inq[500010];
void spfa(){
    while (!q.empty()){
        int u = q.top();
        q.pop();
        inq[u] = 0;
        for (auto v : a[u]){
            if (dis[v] > dis[u]+1){
                dis[v] = dis[u]+1;
                if (!inq[v]){
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
}
void dfs(int x, int num){
    if (x > n){
        for (int i = 1; i <= n; i++) vis1[i] = !vis[i];
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (!vis1[i]){
                dfs1(i);
                cnt++;
            }
        }
        if (cnt > 2) return;
        for (int i = 1; i <= n; i++){
            inq[i] = 0;
            dis[i] = 1e9;
            if (vis[i]){
                q.push(i);
                inq[i] = 1;
                dis[i] = 0;
            }
        }
        spfa();
        int mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, dis[i]);
        ans = min(ans, mx);
        return;
    }
    if (k-num < n-x+1){
        vis[x] = 0;
        dfs(x+1, num);
    }
    if (num+1 <= k){
        vis[x] = 1;
        dfs(x+1, num+1);
    }
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    int c, t, u, v;
    cin >> c >> t;
    while (t--){
        ans = 1e9;
        cin >> n >> k;
        for (int i = 1; i < n; i++){
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1, 0);
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) a[i].clear();
    }
    return 0;
}
