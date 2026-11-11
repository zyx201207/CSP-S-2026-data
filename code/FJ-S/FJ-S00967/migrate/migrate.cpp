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
    const int N = 5005;
    int c, _, n, d, a[N], l[N], f[N][N], g[N][N], bit[N], ans;
    void add(int x, int k) { for (; x <= n; x += x & -x) bit[x] += k; }
    int query(int x) {
        int ret = 0;
        for (; x; x -= x & -x) ret += bit[x];
        return ret;
    }
    void main() {
        read(c, _);
        while (_--) {
            ans = 0;
            read(n, d);
            for (int i = 1; i <= n; i++) {
                read(a[i]);
                l[i] = lower_bound(a + 1, a + i + 1, a[i] - d) - a;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) bit[j] = 0;
                f[i][i] = 0;
                g[i][i] = 1;
                add(i, 1);
                for (int j = i + 1; j <= n; j++) {
                    int k = max(i, l[j]);
                    f[i][j] = f[i][k] + 1;
                    g[i][j] = query(upper_bound(f[i] + i, f[i] + j, f[i][k]) - f[i] - 1) - query(k - 1);
                    add(j, g[i][j]);
                    if (g[i][j] == 2) ans++;
                }
            }
            writeln(ans);
        }
    }
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    W_C_B_H::main();
    return 0;
}
/*
首先有一个显然的 O(n^2 log n) 做法：设 f_{i,j} 表示 i --> j 的最短路，g_{i,j} 表示 i --> j 的最短路方案数
固定出发点然后树状数组优化转移即可，可以拿到 40pts，这个做法应该没什么优化的前途？

显然最短路上不走回头路，记 nxt_i 表示从 i 往后最远可以一次飞到哪里，那么 nxt_i = i 的位置就标志着一个连通块结束了
连边 i --> nxt_i，那么得到若干棵基环树，且这些环都是自环，把环去掉就是内向树
*/