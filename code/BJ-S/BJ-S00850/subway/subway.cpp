#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 502;
const int M = 5e5 + 502;
struct node {
    int v, w;
};
struct ark {
    int u, l;
    bool friend operator < (ark a, ark b) {
        return a.l > b.l;
    }
};
int T, n, m, d, q, inout[M], dis[N][M];
bool vis[M];
priority_queue <ark> pq;
vector <node> edge[M];
void dij (int s) {
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 1; i <= m + n; i++) {
        vis[i] = 0;
    }
    dis[s][s] = 0;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto ist = pq.top();
        pq.pop();
        int u = ist.u;
        int l = ist.l;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto it : edge[u]) {
            int v = it.v;
            int w = it.w;
            if (dis[s][v] > l + w) {
                dis[s][v] = l + w;
                pq.push({v, l + w});
            }
        }
    }
    return;
}
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x3f, sizeof(dis));
    cin >> T >> n >> m >> d >> q;
    for (int i = n + 1; i <= n + m; i++) {
        cin >> inout[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int v, w;
            cin >> v >> w;
            v += n;
            edge[i].push_back({v, w});
            edge[v].push_back({i, w});
        }
    }
    for (int i = 1; i <= n; i++) {
        dij(i);
    }
    for (int i = 1; i <= q; i++) {
        int s, t;
        cin >> s >> t;
        s += n;
        t += n;
        int minn = 0x3f3f3f3f3f3f3f3f;
        for (auto it : edge[s]) {
            int v = it.v;
            int w = it.w;
            minn = min(minn, dis[v][t] + w);
        }
        cout << minn + inout[s] + inout[t] << '\n';
    }
    return 0;
}
/*
奇妙思路
我们从每个地铁线路跑最短路
复杂度 (neloge)
*/
