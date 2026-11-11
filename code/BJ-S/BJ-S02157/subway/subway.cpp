// ========== ACACACACAC ==========
// This is T2.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int BUF_SIZE = 1 << 20;
char ibuf[BUF_SIZE], obuf[BUF_SIZE];
char *ip1 = ibuf, *ip2 = ibuf;
char *op1 = obuf, *op2 = obuf + BUF_SIZE;

inline char gc() {
    if (ip1 == ip2) {
        ip2 = ibuf + fread(ibuf, 1, BUF_SIZE, stdin);
        ip1 = ibuf;
        if (ip1 == ip2) return EOF;
    }
    return *ip1++;
}

inline void pc(char c) {
    if (op1 == op2) {
        fwrite(obuf, 1, BUF_SIZE, stdout);
        op1 = obuf;
    }
    *op1++ = c;
}

inline void f() {
    fwrite(obuf, 1, op1 - obuf, stdout);
}

inline int in() {
    int res = 0;
    char c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) (res = res * 10 + c - '0'), c = gc();
    return res;
}

inline void out(ll x) {
    char stk[30];
    int cnt = 0;
    while (x > 0) {
        stk[cnt++] = (x % 10) + '0';
        x /= 10;
    }
    while (cnt > 0) pc(stk[--cnt]);
    pc('\n');
}

const int M = 5e5 + 5;
const int N = 505;

int c, n, m, d, q; ll w[M];
vector<pii> g[M];

ll dis[N][N];

inline void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                dis[j][i] = dis[i][j];
            }
        }
    }
}

inline ll slove(int x, int y) {
    ll ans = 1e18;
    for (pii px : g[x]) {
        int xu = px.first, xw = px.second;
        for (pii py : g[y]) {
            int yu = py.first, yw = py.second;
            ans = min(ans, xw + yw + dis[xu][yu]);
        }
    }
    return ans;
}

inline void solve() {
    c = in(); n = in(); m = in(); d = in(); q = in();
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; ++i) w[i] = ll(in());
    for (int i = 1; i <= n; ++i) {
        int k = in();
        dis[i][i] = 0;
        for (int j = 1; j <= k; ++j) {
            int a = in(), t = in();
            g[a].emplace_back(i, t);
        }
    }

    for (int i = 1; i <= m; ++i) {
        int sz = g[i].size();
        for (int j = 0; j < sz; ++j) {
            for (int k = j + 1; k < sz; ++k) {
                int u = g[i][j].first, v = g[i][k].first;
                ll w = g[i][j].second + g[i][k].second;
                dis[u][v] = dis[v][u] = min(dis[u][v], w);
            }
        }
    } floyd();

    while (q--) {
        int x = in(), y = in();
        out(slove(x, y) + w[x] + w[y]);
    }
    f();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    solve();
}

/*
80~100 pts
MD^2+N^3+QD^2
fread/fwrite NB!

scallion!
anoscope!
eplipsey!
program!
brace!

   /\
  /  \
 /____\
| .  . |
|      |
|  /_  |
|      |
|  \/  |
 \    /
  \__/
yaochi faxing
*/