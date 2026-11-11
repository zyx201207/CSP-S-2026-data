// ++rp
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';

using namespace std;
#define int long long

void solve()
{
    int n, m, d, q;
    cin >> n >> m >> d >> q;
    vector<int> W(m + 1), WW(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> W[i];
    vector<vector<pair<int, int>>> g(m + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int last = 0;
        for (int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            if (j == 1) {
                WW[x] = y;
                last = x;
            } else {
                g[last].emplace_back(x, y);
                g[x].emplace_back(last, y);
            }
        }
    }
    vector<vector<int>> di(m + 1);
    const int inf = 0x3f3f33f3f3f3f3f;
    for (int start = 1; start <= m; start++) {
        vector<int>& dist = di[start];
        dist.resize(m + 1, inf);
        dist[start] = W[start] + WW[start];
        priority_queue<pair<int, int>> q;
        q.emplace(-dist[start], start);
        while (!q.empty()) {
            int u = q.top().second;
            if (-q.top().first != dist[u]) {
                q.pop();
                continue;
            }
            q.pop();
            for (auto p : g[u]) {
                int v = p.first;
                int w = p.second + WW[v];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.emplace(-dist[v], v);
                }
            }
        }
        for (int i = 1; i <= m; i++)
            if (dist[i] != inf)
                dist[i] += W[i] - WW[i];
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << di[x][y] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c;
    cin >> c;
    solve();
    return 0;
}