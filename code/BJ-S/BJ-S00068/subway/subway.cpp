#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll rd() {
    ll x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
void wt(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x <= 9) putchar(x + '0');
    else wt(x / 10), putchar(x % 10 + '0');
}
int w[500005], k[505], ans[100005];
ll dis[500505];
bool vis[500505];
vector<pair<int, ll>> g[500505];
vector<pair<int, int>> qu[500505];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    for (int i = 1; i <= m; ++i) {
        w[i] = rd();
    }
    for (int i = 1; i <= n; ++i) {
        k[i] = rd();
        for (int j = 1; j <= k[i]; ++j) {
            int a = rd(), t = rd();
            g[i+m].push_back({a, t});
            g[a].push_back({i + m, t});
        }
    }
    for (int i = 1; i <= q; ++i) {
        int x = rd(), y = rd();
        if (x > y) swap(x, y);
        qu[x].push_back({y, i});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 1; i <= n; ++i) {
        if (qu[i].empty()) continue;
        for (int j = 1; j <= n + m; ++j) dis[j] = 1e18, vis[j] = false;
        dis[i] = 0;
        pq.push({0, i});
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto x : g[u]) {
                int v = x.first;
                ll w = x.second;
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        for (auto x : qu[i]) ans[x.second] = dis[x.first] + w[i] + w[x.first]; 
    }
    for (int i = 1; i <= q; ++i) wt(ans[i]), putchar('\n');
}