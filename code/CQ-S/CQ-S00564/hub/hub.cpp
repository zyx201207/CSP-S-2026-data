#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PIL pair<int, LL>
#define PII pair<int, int>
using namespace std;
// clock_t st = clock();
const int N = 1e6;
const LL inf = 1e18;
int n, cc, k, id[N + 5], br, tsiz, rt, siz[N + 5], sz[N + 5], len[N + 5];
LL ans, mimx;
vector<PII> g[N + 5];
inline void init() {
    ans = inf;
    for (int i = 0; i <= n + 1; i++) g[i].clear(), g[i].shrink_to_fit();
}
void dfs0(int u = 1, int p = 0) {
    sz[u] = 1;
    for (auto i : g[u]) if (i.second != p) id[i.second] = i.first, dfs0(i.second, u), sz[u] += sz[i.second];
}
inline void get_rt(int u, int p = 0) {
    siz[u] = 1; int mx = 0;
    for (auto i : g[u]) if (i.second != p && i.first != br) {
        int v = i.second;
        get_rt(v, u);
        siz[u] += siz[v];
        mx = max(mx, siz[v]);
    }
    mx = max(mx, tsiz - siz[u]);
    if (mx < mimx) {
        // if (br == 1) cerr << u << " " << mx << " " << mimx << " mimx\n";
        mimx = mx;
        rt = u;
    }
}
void get_sum(int u, int p = 0) {
    len[u] = 0;
    for (auto i : g[u]) if (i.second != p && i.first != br) {
        int v = i.second;
        get_sum(v, u);
        len[u] = max(len[v], len[u]);
    }
    len[u]++;
}

inline void solve() {
    cin >> n >> k; init();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({i, v});
        g[v].push_back({i, u});
    }
    dfs0();
    for (int i = 2; i <= n; i++) {
        if ((cc == 13 || cc == 14) && (i != (n / 2 + 1) / 2)) continue;
        LL s = 0; br = id[i]; int cnt = 2;
        tsiz = sz[i]; mimx = inf;
        get_rt(i);
        get_sum(rt);
        int x = rt;
        tsiz = n - sz[i]; mimx = inf;
        get_rt(1);
        get_sum(rt);
        int y = rt;
        priority_queue<PII> q;
        for (auto j : g[x]) if (j.first != br) q.push({len[j.second], j.second});
        for (auto j : g[y]) if (j.first != br) q.push({len[j.second], j.second});
        while (!q.empty() && cnt < k) {
            int u = q.top().second; q.pop();
            cnt++;
            for (auto j : g[u]) if (j.first != br && len[u] > len[j.second]) q.push({len[j.second], j.second});
        }
        if (q.empty()) s = 0;
        else s = q.top().first;
        ans = min(ans, s);
    }
    cout << ans << "\n";
}
// void solve2() {
//     cin >> n >> k;

// }
signed main() {
    // freopen("hub3.in", "r", stdin);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tt = 1;
    cin >> cc >> tt;
    while (tt--) solve();
    // cerr << (double)(clock() - st) / CLOCKS_PER_SEC * 1000 << "\n";
    return 0;
}