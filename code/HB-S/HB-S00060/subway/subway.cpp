# include <bits/stdc++.h>
using namespace std;
const int N = 2.5e5 + 10;
long long w[N], dis[N << 2];
long long a[510][N], t[510][N];
bitset<1000000> vis;
int in[N << 2];
vector<pair<int, long long> > G[N << 1];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, Q;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &Q);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &w[i]);
    }
    int cnt = m;
    /*
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%lld%lld", &a[i][j], &t[i][j]);
            if (j > 1) {
                G[a[i][j] + m * i].push_back({a[i][j - 1] + m * i, 0});
                G[a[i][j - 1] + m * i].push_back({a[i][j] + m * i, 0});
            }
            G[a[i][j]].push_back({a[i][j] + m * i, t[i][j]});
            G[a[i][j] + m * i].push_back({a[i][j], t[i][j]});
        }
    }
    */
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%lld%lld", &a[i][j], &t[i][j]);
            G[a[i][j]].push_back({i + m, t[i][j]});
            G[m + i].push_back({a[i][j], t[i][j]});
        }
    }
    memset(dis, 0x7f, sizeof(dis));
    priority_queue<pair<long long, int> > q;
    q.push({0, 1});
    dis[1] = 0;
    in[1] = 1;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (pair<int, long long> now : G[u]) {
            int v = now.first;
            if (now.second + dis[u] < dis[v]) {
                dis[v] = dis[u] + now.second;
                q.push({-dis[v], v});
            }
        }
    }
    while (Q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        /*priority_queue<pair<long long, int> > q;
        while (!q.empty()) {
            int u = q.top().second;
            for (pair<int, long long> now : G[u]) {
                int v = now.first, w = now.second;
                if ()
            }
        }*/
        printf("%lld\n", abs(dis[u] - dis[v]) + w[u] + w[v]);
    }
    return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
