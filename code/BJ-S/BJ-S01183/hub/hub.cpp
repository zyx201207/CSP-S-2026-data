#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int c, t, n, k, b[maxn], tot, dis[maxn], ans, vis[maxn];
vector<int> g[maxn];
unordered_set<int> st;
void dfs(int x) {
    vis[x] = true;
    for(int y : g[x]) {
        if(vis[y]) continue;
        if(st.find(y) == st.end()) continue;
        dfs(y);
    }
}
bool check() {
    memset(vis, 0, sizeof(vis));
    st.clear();
    int cnt = 0;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        if(b[i]) {
            v.push_back(i);
            st.insert(i);
        }
    }
    for(int x : v) {
        if(!vis[x]) {
            cnt++;
            if(cnt > 2) return 1;
            dfs(x);
        }
    }
    return 0;
}
void bfs() {
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(b[i]) {
            q.push(i);
            dis[i] = 0;
        }
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int y : g[x]) {
            if(dis[y] == 0x3f3f3f3f3f3f3f3f) {
                dis[y] = dis[x]+1;
                q.push(y);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, dis[i]);
    ans = min(ans, res);
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        ans = 1e18;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int mask = 0; mask < (1<<n); mask++) {
            memset(b, 0, sizeof(b));
            int tmp = mask, cnt = 0;
            tot = 0;
            while(tmp) {
                b[++tot] = tmp&1;
                cnt += tmp&1;
                tmp>>=1;
            }
            if(cnt != k) continue;
            if(check()) continue;
            bfs();
        }
        cout << ans << "\n";
    }
    return 0;
}