#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int N = 1e6 + 1000;
const int inf = 1e9;

vector<pair<ll, ll>>adj[N];

ll c, n, m, d, q;
vector<ll> dis(N, inf);
vector<ll> vis(N, 0);
map<ll,ll>pre;

void dij(ll s) {
    for (int i = 0; i <= 2 * m + n + 1; i++) {
        dis[i] = inf;
        vis[i] = 0;
    }
    dis[s] = 0;
    // pair<long long,long long> => <w,v>
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>>
        pq;

    pq.emplace(0, s);
    while (!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto edg : adj[u]) {
            auto v = edg.first, w = edg.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pre[v] = u;
                pq.emplace(dis[v], v);
            }
        }
    }
}


int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        ll x;
        cin >> x;
        adj[i].emplace_back(i + m, x);
        adj[i + m].emplace_back(i, x);
    }
    for (int i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            // 第i线 j站台
            ll x, y;
            cin >> x >> y;
            adj[x + m].emplace_back(2 * m + i, y);
            adj[2 * m + i].emplace_back(x + m, y);
        }
    }
    for (int i = 1; i <= q; i++) {
        ll x, y;
        cin >> x >> y;
        dij(x);
        cout << dis[y] << endl;
    }
}

/*
1 ~ m 站口
m+1 ~ 2 * m 对应站厅
2 * m + i i号线
*/