#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
int n, k, dep[N], mxdep[N], S[N], ans, dis[11];
vector <int> v[N];
bool vis[N];

int bfs () {
    memset (dis, -1, sizeof(dis));
    queue <int> q;
    int res = 0;
    for (int i = 1; i <= k; ++i) dis[S[i]] = 0, q.push(S[i]);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        res = max(res, dis[x]);
        for (int y : v[x]) {
            if (dis[y] == -1) {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    return res;
}

void dfs (int step, int cnt) {
    if (cnt + (n - step + 1) < k) return ;
    if (cnt == k) {
        ans = min(ans, bfs());
        return ;
    }
    dfs(step + 1, cnt);
    S[cnt + 1] = step, vis[step] = 1;
    dfs(step + 1, cnt + 1);
    S[cnt + 1] = 0, vis[step] = 0;
}

void solve () {
    cin >> n >> k; ans = n;
    for (int i = 1; i <= n; ++i) v[i].clear();
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    int Case, T; cin >> Case >> T;
    while (T--) solve();
    return 0;
}
