#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

class Pair {
public: int a; ll t;
};

class Edge {
public: int y; ll z;
};

int c, n, m, q, d;
bool book[510];
ll w[500010], dis[510];
vector<Pair> sta[510], ri[500010];
vector<Edge> E[550], G[550];

class Node {
public: int x; ll t;
    bool operator < (const Node & _x) const { return t > _x.t; }
};

inline void dijkstra() {
    priority_queue<Node> q;
    for (int i = 1; i <= n + 2; ++i) book[i] = false, dis[i] = INF;
    dis[n + 1] = 0;
    q.push({n + 1, 0});
    while (!q.empty()) {
        Node h = q.top(); q.pop();
        int x = h.x; ll t = h.t;
        if (book[x]) continue;
        book[x] = true;
        for (Edge e : G[x]) {
            int y = e.y; ll z = e.z;
            if (dis[y] > t + z) dis[y] = t + z, q.push({y, dis[y]});
        }
    }
}

inline int readi() {
    int _x = 0; char _c = getchar();
    while (_c > '9' && _c < '0') _c = getchar();
    while (_c >= '0' && _c <= '9') _x = _x * 10 + _c - '0', _c = getchar();
    return _x;
}

inline int readll() {
    ll _x = 0; char _c = getchar();
    while (_c > '9' && _c < '0') _c = getchar();
    while (_c >= '0' && _c <= '9') _x = _x * 10 + _c - '0', _c = getchar();
    return _x;
}

inline void write(ll _x) {
    if (_x > 9) write(_x / 10);
    putchar(_x % 10 + '0');
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    c = readi(), n = readi(), m = readi(), d = readi(), q = readi();

    for (int i = 1; i <= m; ++i) w[i] = readll();

    for (int i = 1; i <= n; ++i) {
        int k;
        k = readi();
        for (int j = 1; j <= k; ++j) {
            int ai; ll ti; ai = readi(), ti = readll();
            sta[i].push_back({ai, ti});
            ri[ai].push_back({i, ti});
        }
    }

    for (int i = 1; i <= n; ++i)
        for (Pair s : sta[i]) {
            for (Pair v : ri[s.a]) {
                if (v.a == i) continue;
                E[i].push_back({v.a, v.t + s.t});
            }
        }


    for (int i = 1; i <= q; ++i) {
        int x, y; x = readi(), y = readi();
        for (int j = 1; j <= n + 2; ++j) G[j] = E[j];
        for (Pair p : ri[x]) G[n + 1].push_back({p.a, p.t + w[x]});
        for (Pair p : ri[y]) G[p.a].push_back({n + 2, p.t + w[y]});
        dijkstra();
        write(dis[n + 2]);
        putchar('\n');
    }

    return 0;
}
