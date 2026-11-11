#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i128 __int128
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using p3i = pair<int, pii>;
#define eb emplace_back
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
const int inf = 0x3f3f3f3f;
const long long Inf = 0x3f3f3f3f3f3f3f3f;
template<typename T, typename U> void chkmin(T &x, U y) { x > y && (x = y); }
template<typename T, typename U> void chkmax(T &x, U y) { x < y && (x = y); }

#define gc getchar_unlocked
namespace IO {
    void read(int &x) { x = 0; char c = gc(); bool f = 0; while (!isdigit(c)) { if (c == '-') { f = 1; } c = gc(); } while (isdigit(c)) { x = (x << 3) + (x << 1) + (c ^ 48); c = gc(); } if (f) x = -x; }
    void write(int x) { if (x < 0) { putchar('-'); x = -x; } string s = ""; do { s += x % 10 ^ 48; x /= 10; } while (x); for (int i = s.size() - 1; ~i; i--) putchar(s[i]); }
    template<typename T, typename... U> void read(T &x, U &...y) { read(x); read(y...); }
    template<typename T, typename... U> void write(T x, U... y) { write(x); write(y...); }
    template<typename T, typename... U> void writeln(T x, U... y) { write(x, y...); puts(""); }
}

namespace W_C_B_H { // 关注 Luogu 527300 谢谢喵
    using namespace IO;
    const int N = 505, M = 500005;
    int c, n, m, d, q, b[M], e[N][N], dis[N][N];
    vector<pii> a[M], g[N];
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    void dijkstra(int s) {
        Q.push({0, s});
        while (!Q.empty()) {
            pii t = Q.top();
            Q.pop();
            int u = t.se, di = t.fi;
            if (di > dis[s][u]) continue;
            for (pii i : g[u]) {
                int v = i.fi, w = i.se;
                if (dis[s][v] > di + w) {
                    dis[s][v] = di + w;
                    Q.push({dis[s][v], v});
                }
            }
        }
    }
    void main() {
        memset(e, 0x3f, sizeof e);
        memset(dis, 0x3f, sizeof dis);
        read(c, n, m, d, q);
        for (int i = 1; i <= m; i++) read(b[i]);
        for (int i = 1, k, x, y; i <= n; i++) {
            read(k);
            while (k--) {
                read(x, y);
                a[x].eb(i, y);
            }
            e[i][i] = dis[i][i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                for (int k = j + 1; k < a[i].size(); k++) {
                    int u = a[i][j].fi, v = a[i][k].fi, w = a[i][j].se + a[i][k].se;
                    chkmin(e[u][v], w);
                    chkmin(e[v][u], w);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (e[i][j] < Inf) g[i].eb(j, e[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) dijkstra(i);
        while (q--) {
            int x, y, ans = Inf;
            read(x, y);
            for (pii i : a[x]) for (pii j : a[y]) chkmin(ans, i.se + dis[i.fi][j.fi] + j.se);
            writeln(b[x] + ans + b[y]);
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    W_C_B_H::main();
    return 0;
}
/*
n 和 d 很小，所以从地铁线路入手
由于坐地铁的时间不重要，所以考虑把一条地铁线路缩成一个点
两条地铁线路 u,v 之间连边当且仅当二者可以直接换乘，且边权为所有换乘站的换乘时间的最小值
然后跑一下全源最短路
对于查询 x,y，O(d^2) 枚举经过 x,y 的地铁线路，然后是个人都会做了
15:20 开始写代码
15:36 通过全部大样例
17:57 “大家听一下，题目有修正。第二题样例解释部分，请忽略公式中的变量部分，以文字叙述和公式中的数值部分为准。”
*/