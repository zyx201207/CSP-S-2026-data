#include <bits/stdc++.h>
#define ch(opt, tar, ...) tar = opt({tar, __VA_ARGS__})
#define isz(x) (int((x).size()))
#define inlfc __attribute__((always_inline)) inline
using namespace std;
typedef long long ll;
typedef __int128_t i128;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

constexpr ll INF = 2e18;

template<typename T>
inlfc void read(T &x) {
    x = 0;
    char ch;
    while ((ch = getchar_unlocked()) && (ch < '0' || ch > '9'));
    do (x *= 10) += ch - '0';
    while ((ch = getchar_unlocked()) && '0' <= ch && ch <= '9');
}

inlfc void dijkstra(const vector<vector<pil>> &G, vector<ll> &d, int s) {
    d = vector<ll>(d.size(), INF);
    d[s] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        const auto [dis, u] = q.top();
        q.pop();
        if (dis > d[u]) continue;
        for (auto &[v, w] : G[u])
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d ,q;
    read(c); read(n); read(m); read(d); read(q);
    vector<int> w(m + 1);
    vector<vector<ll>> d_sub(n + 1, vector<ll>(n + 1));
    vector<vector<pil>> rel_sta(m + 1), bet_sub(n + 1);
    for (int i = 1; i <= m; i ++) read(w[i]);
    for (int i = 1; i <= n; i ++) {
        int k;
        read(k);
        for (int j = 1; j <= k; j ++) {
                int a, t;
                read(a); read(t);
                rel_sta[a].emplace_back(i, t);
        }
    }
    for (int i = 1; i <= m; i ++)
        for (auto &[u, g] : rel_sta[i])
            for (auto &[v, h] : rel_sta[i])
                if (u != v) bet_sub[u].emplace_back(v, g + h);
    for (int i = 1; i <= n; i ++)
        dijkstra(bet_sub, d_sub[i], i);
    for (int _ = 1; _ <= q; _ ++) {
        int x, y;
        ll ans = INF;
        read(x); read(y);
        for (auto &[u, g] : rel_sta[x])
            for (auto &[v, h] : rel_sta[y])
                ch(min, ans, g + d_sub[u][v] + h);
        printf("%lld\n", w[x] + w[y] + ans);
    }
    /*
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++)
            cerr << d_sub[i][j] << ' ';
        cerr << '\n';
    }
    */
    return 0;
}
/*我去考场竟然提供git，用了用了*/