// ++rp
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';

using namespace std;
#define int long long

void solve()
{
    int n;
    int d;
    cin >> n >> d;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (llabs(x[i] - x[j]) <= d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans = 0;
    const int inf = 0x3f3f3f3f;
    for (int start = 0; start < n - 1; start++) {
        queue<int> q;
        q.push(start);
        vector<int> dist(n, inf), cnt(n);
        cnt[start] = 1;
        dist[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (cnt[u] > 2)
                continue;
            for (int v : g[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    cnt[v] = cnt[u];
                    q.push(v);
                } else if (dist[u] + 1 == dist[v]) {
                    cnt[v] += cnt[u];
                    q.push(v);
                }
            }
        }
        for (int i = start + 1; i < n; i++)
            if (cnt[i] == 2)
                ans++;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c;
    int T;
    cin >> c >> T;
    while (T--) {
        solve();
    }
    return 0;
}
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// wo bei cfc bang jia le jiu jiu wo