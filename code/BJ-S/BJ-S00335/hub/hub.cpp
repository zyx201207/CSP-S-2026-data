#include<bits/stdc++.h>
#define fo(i, l, r) for(int i = (l); i <= (r); ++i)
using namespace std;
int c, T, n, k, s[1000005], vis[1000005];
vector<int> e[1000005];
void search(int u, int col){
    vis[u] = true;
    for(auto v : e[u]){
        if(vis[v] || s[v] != col) continue;
        vis[v] = true;
        search(v, col);
    }
    return;
}
int dis[1000005];
inline int bfs(int u){
    fo(i, 1, n) dis[i] = n;
    queue<int> q;
    q.push(u), dis[u] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(s[u]) return dis[u];
        for(auto v : e[u]){
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return n + 1;
}
int ans;
void dfs(int x){
    if(x > n){
        int cc = 0;
        fo(i, 1, n) if(s[i]) cc++;
        if(cc != k) return;
        fo(i, 1, n) vis[i] = false;
        bool f1 = false, f2 = false;
        fo(i, 1, n) if(!vis[i]){
            if(s[i] == 1){
                if(f1) return;
                f1 = true;
                search(i, 1);
            }
            if(s[i] == 2){
                if(f2) return;
                f2 = true;
                search(i, 2);
            }
        }
        int mx = 0;
        fo(i, 1, n) mx = max(mx, bfs(i));
        ans = min(ans, mx);
        return;
    }
    s[x] = 0, dfs(x + 1);
    s[x] = 1, dfs(x + 1);
    s[x] = 2, dfs(x + 1);
    return;
}
signed main(){
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> T; while(T--){
        cin >> n >> k;
        fo(i, 2, n){
            int u, v; cin >> u >> v;
            e[u].push_back(v), e[v].push_back(u);
        }
        ans = n, dfs(1);
        cout << ans << '\n';
        fo(i, 1, n) e[i].clear();
    }
    return 0;
}
// g++ hub.cpp -o hub -O2 -std=c++14 -static