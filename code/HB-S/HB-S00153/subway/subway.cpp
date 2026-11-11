#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500, K = 2e4;
struct Point {
    int id, w;
};
bool operator < (Point x, Point y) {
    return x.w > y.w;
}
vector<Point> g[N + K + 5];
int w[N + 5];
int a[K + 5];
int dis[N + K + 5];
priority_queue<Point> q;
void dijkstra(int id) {
    dis[id] = 0;
    q.push({id, 0});
    while (!q.empty()) {
        int t = q.top().id;
        q.pop();
        for (Point nxt : g[t]) {
            if (dis[nxt.id] > dis[t] + nxt.w) {
                dis[nxt.id] = dis[t] + nxt.w;
                q.push({nxt.id, dis[nxt.id]});
            }
        }
    }
}

int cs;

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, d, T;
    cin >> cs >> n >> m >> d >> T;
    for (int i = 1; i <= m; i ++) 
        cin >> w[i];
    int curr = m;
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++) {
            cin >> a[j];
            int t;
            cin >> t;
            g[a[j]].push_back({curr + j, t});
            g[curr + j].push_back({a[j], t});
        }
        curr ++;
        for (int j = 1; j < k; j ++) {
            g[curr].push_back({curr + 1, 0});
            g[curr + 1].push_back({curr, 0});
            curr ++;
        }
    }
    while (T --) {
        int u, v;
        cin >> u >> v;
        for (int i = 0; i <= curr; i ++)
            dis[i] = 9e18;
        dijkstra(u);
        cout << dis[v] + w[u] + w[v] << endl;
    }
    // for (int i = 1; i <= 11; i ++)  {
    //     for (Point j : g[i])
    //         fprintf(stderr, "{%lld, %lld, %lld} ", i, j.id, j.w);
    //     fprintf(stderr, "\n");
    // }
    return 0;
}