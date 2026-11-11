#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
vector<int> w;
vector<map<int, int>> to_platform;
struct line {
    int v;
    int number;
};
vector<vector<line>> mp;
vector<int> vis;
int ans = 0;
int bfs(int start, int end) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, function<bool(tuple<int, int, int>, tuple<int, int, int>)>> pq([&](tuple<int, int, int> x, tuple<int, int, int> y) {
        int _;
        int a, b;
        tie(_, a, _) = x;
        tie(_, b, _) = y;
        return a > b;
    });
    pq.push({start, 0, -1});
    int ans = numeric_limits<int>::max();
    vis[start] = 0;
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int u, sum, lastline;
        tie(u, sum, lastline) = front;
        if (u == end) {
            sum += to_platform[u][lastline];
            ans = min(ans, sum);
            continue;
        }
        for (line l: mp[u]) {
            int v = l.v;
            int number = l.number;
            int cost = sum;
            if (lastline != -1) {
                if (number != lastline) {
                    cost += to_platform[u][lastline] + to_platform[u][number];
                }
            } else {
                cost += to_platform[u][number];
            }
            if (vis[v] > cost + to_platform[u][number]) {
                pq.push({v, cost, number});
                vis[v] = cost + to_platform[u][number];
            }
        }
    }
    return ans;
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    w.assign(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    to_platform.assign(m + 1, map<int, int>());
    mp.assign(m + 1, vector<line>());
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        int laststa = -1;
        for (int j = 1, a, t; j <= k; j++) {
            cin >> a >> t;
            to_platform[a][i] = t;
            if (laststa != -1) {
                mp[a].push_back({laststa, i});
                mp[laststa].push_back({a, i});
            }
            laststa = a;
        }
    }
    for (int i = 1, x, y; i <= q; i++) {
        ans = 0;
        vis.assign(m + 1, numeric_limits<int>::max());
        cin >> x >> y;
        ans = w[x] + w[y] + bfs(x, y);
        cout << ans << "\n";
    }
    return 0;
}