#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef long long ll;
const int M = 5e5;
const int N = 500;
const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *p1 = ibuf, *p2 = ibuf;
char obuf[BUFSIZE], *p3 = obuf;

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, BUFSIZE, stdin), p1 == p2) ? EOF : *p1++)
#define pc(x) (p3 - obuf < BUFSIZE ? *p3++ = (x) : (fwrite(obuf, 1, BUFSIZE, stdout), p3 = obuf, *p3++ = (x)))

inline void flush() {
    if (p3 != obuf)
        fwrite(obuf, 1, p3 - obuf, stdout);
}

inline int read() {
    int x = 0, w = 1;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-')
            w = -1;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    return x * w;
}

inline void wrt(ll x) {
    if (x < 0) {
        pc('-');
        x = -x;
    }
    char stk[20], tp = 0;
    do {
        stk[tp++] = x % 10 + 48;
        x /= 10;
    } while (x);
    while (tp--)
        pc(stk[tp]);
}

inline bool cmn(ll &x, ll y) {
    if (x > y) {
        x = y;
        return 1;
    }
    return 0;
}

int n;
int m;
int d;
int q;
int w[M + 3];
ll dis[N + 3][N + 3];
vector<pair<int, int>> G[M + 3];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++)
        w[i] = read();
    for (int i = 1, k; i <= n; i++) {
        k = read();
        for (int j = 1, a, t; j <= k; j++) {
            a = read(), t = read();
            G[a].push_back({t, i});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        assert(G[i].size() <= d);
        for (int j = 0; j < G[i].size(); j++)
            for (int k = j + 1, u, v, w; k < G[i].size(); k++) {
                u = G[i][j].se, v = G[i][k].se, w = G[i][j].fi + G[i][k].fi;
                cmn(dis[u][v], w);
                cmn(dis[v][u], w);
            }
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cmn(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1, x, y; i <= q; i++) {
        x = read(), y = read();
        ll rs = 0x3f3f3f3f3f3f3f3f;
        for (int j = 0; j < G[x].size(); j++)
            for (int k = 0, u, v; k < G[y].size(); k++) {
                u = G[x][j].se, v = G[y][k].se;
                cmn(rs, G[x][j].fi + G[y][k].fi + dis[u][v]);
            }
        wrt(rs + w[x] + w[y]), pc('\n');
    }
    flush();
    return 0;
}