#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1005;

int c, t, n, k, dis[N][N], T;
vector <int> G[N];
bool fl[N], vis[N];

inline void dfs(int u) {
    // if (T == 322) cerr << "dfs" << ' ' << u << '\n';

    for (const int &v : G[u]) if (fl[v] && !vis[v]) vis[v] = true, dfs(v);
    return void();
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin.tie(0), cout.tie(0);

    cin >> c >> t;
    while (t--) {
        // cerr << "test" << '\n';

        cin >> n >> k;
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            G[u].emplace_back(v), G[v].emplace_back(u);
        }

        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i <= n; ++i) {
            dis[i][i] = 0;
            queue <int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const int &v : G[u]) if (dis[i][v] == 0x3f3f3f3f) {
                    dis[i][v] = dis[i][u] + 1;
                    q.push(v);
                }
            }
        }

        int ans = INT_MAX;

        for (int S = 0; S < (1 << n); ++S) if (__builtin_popcount(S) == k) {
            T = S;

            // if (S == 322) cerr << "322" << '\n';

            int res = 0;
            for (int i = 0; i < n; ++i)
                if ((S >> i) & 1) fl[i + 1] = true;
                else fl[i + 1] = false;
            memset(vis, 0, sizeof vis);
            int num = 0;
            for (int i = 1; i <= n; ++i)
                if (!fl[i] || vis[i]) continue;
                else vis[i] = true, ++num, dfs(i);

            // if (S == 322) cerr << num << '\n';

            if (num > 2) continue;

            // cerr << "OK" << '\n';

            for (int i = 1; i <= n; ++i) {
                int d = 0x3f3f3f3f;
                for (int j = 1; j <= n; ++j) if (fl[j]) d = min(d, dis[i][j]);
                res = max(res, d);
            }
            ans = min(ans, res);
        }

        cout << ans << '\n';
    }

    return 0;
}