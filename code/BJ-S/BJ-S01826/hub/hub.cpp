#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int t, n, k, d[1005][1005]; bool v[N], vis[N];
vector <int> e[N];
void dfs(int x, int nfa, int r) {
    d[r][x] = d[r][nfa] + 1;
    for (int i : e[x]) if (i != nfa) dfs(i, x, r);
}
void calc(int x) {
    if (!v[x] || vis[x]) return;
    vis[x] = 1;
    for (int i : e[x]) calc(i);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            e[u].push_back(v), e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) d[i][0] = -1, dfs(i, 0, i);
        if (k == 2) {
            int ans = INT_MAX;
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++) {
                    int now = 0;
                    for (int k = 1; k <= n; k++)
                        now = max(now, min(d[i][k], d[j][k]));
                    ans = min(ans, now);
                }
            cout << ans << '\n';
            for (int i = 1; i <= n; i++) e[i].clear();
            continue;
        }
        int ans = INT_MAX;
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) cnt += ((i >> j) & 1);
            if (cnt != k) continue;
            for (int j = 1; j <= n; j++)
                v[j] = ((i >> (j - 1)) & 1), vis[j] = 0;
            int ncnt = 0, now = 0;
            for (int j = 1; j <= n; j++)
                if (v[j] && !vis[j]) calc(j), ncnt++;
            if (ncnt > 2) continue;
            for (int j = 1; j <= n; j++) {
                int cur = INT_MAX;
                for (int k = 1; k <= n; k++)
                    if (v[k]) cur = min(cur, d[k][j]);
                now = max(now, cur);
            }
            ans = min(ans, now);
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) e[i].clear();
    }
    return 0;
}
