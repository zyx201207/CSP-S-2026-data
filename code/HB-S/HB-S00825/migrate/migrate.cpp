#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int N = 5002;

int c, t, n, deg[N], dg[N];
ll d, x[N];
int dis[N][N], num[N][N];

int main() {
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);

    cin.tie(0), cout.tie(0);

    cin >> c >> t;

    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i], deg[i] = 0;

        vector <int> G[n + 2];
        for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j)
            if (x[j] - x[i] <= d) G[i].emplace_back(j), ++deg[j];

        for (int st = 1; st <= n; ++st) {
            for (int j = st; j <= n; ++j) dis[st][j] = 10000, num[st][j] = 0, dg[j] = deg[j];
            queue <int> q;
            q.push(st), dis[st][st] = 0, num[st][st] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const int &v : G[u]) {
                    --dg[v];
                    if (!dg[v]) q.push(v);
                    if (dis[st][u] + 1 < dis[st][v]) dis[st][v] = dis[st][u] + 1, num[st][v] = num[st][u];
                    else if (dis[st][u] + 1 == dis[st][v]) num[st][v] += num[st][u];
                }
            }
            for (const int &x : G[st]) --deg[x];
        }

        int ans = 0;

        for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) if (num[i][j] == 2) ++ans;

        // for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) cerr << i << ' ' << j << ' ' << dis[i][j] << ' ' << num[i][j] << '\n';

        cout << ans << '\n';
    }

    return 0;
}