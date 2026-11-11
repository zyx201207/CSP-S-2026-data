#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
int c;
const int M = 5e5;
const int N = 500;
int n, m, d;
vector<int> w;
map<int, ll> e[M+N+5];


ll dist[M+N+5];
bool vis[M+N+5];
ll dijkstra(int p, int y) {
    memset(dist, (int)INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[p] = 0;
    while (!vis[y] && p != y) {
        vis[p] = 1;
        for (pair<int, ll> it : e[p]) {
            dist[it.first] = min(dist[it.first], dist[p] + it.second);
        }
        p = 0;
        for (int i = 1; i <= M+n; ++i) {
            if (i == m+1) i = M+1;
            if (!vis[i] && dist[i] < dist[p]) {
                p = i;
            }
        }
    }
    return dist[y];
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> c >> n >> m >> d >> q;
    w.resize(m+1);
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a, t;
            cin >> a >> t;
            e[M+i].insert({a, t});
            e[a].insert({M+i, t});
        }
    }
    while (q--) {
        int x, y;
        ll t;
        cin >> x >> y;
        cout << w[x] + dijkstra(x, y) + w[y] << '\n';
    }
    return 0;
}
