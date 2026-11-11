#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 66, M = 7777;
int c, T, n, k, D[N], d[M][M], ok[N], f[N];
vector<int> to[N];
int findfa(int x) {
	if (f[x] == x) return x;
	return (f[x] = findfa(f[x]));
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = d[j][i] = 1e18;
        for (int i = 1; i <= n; i++)
            to[i].clear(), d[i][i] = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            to[u].push_back(v);
            to[v].push_back(u);
            d[u][v] = d[v][u] = 1;
        }
        for (int p = 1; p <= n; p++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
        int top = (1ll << n), ans = 1e18;
        for (int st = 1; st < top; st++) {
            int tmp = st, cnt = 0;
            for (int i = 1; i <= n; i++) {
                ok[i] = tmp % 2;
                cnt += ok[i];
                f[i] = i;
                tmp /= 2;
            }
            if (cnt != k) continue;
            for (int i = 1; i <= n; i++) {
                if (!ok[i]) continue;
                int x = findfa(i);
                for (auto j : to[i]) {
                    if (!ok[j]) continue;
                    int y = findfa(j);
                    f[y] = x;
                }
            }
            set<int> S;
            for (int i = 1; i <= n; i++)
                if (ok[i]) S.insert(findfa(i));
            if (S.size() > 2) continue;
            for (int i = 1; i <= n; i++)
                D[i] = (ok[i] ? 0 : 1e18);
            for (int i = 1; i <= n; i++) {
                if (ok[i]) continue;
                for (int j = 1; j <= n; j++)
                    if (ok[j]) D[i] = min(D[i], d[i][j]);
            }
            int mx = 0;
            for (int i = 1; i <= n; i++) mx = max(mx, D[i]);
            ans = min(ans, mx);
        }
        cout << ans << "\n";
    }
    return 0;
}
