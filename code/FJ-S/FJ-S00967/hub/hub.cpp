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
    const int N = 1000005, LOG = 21;
    int c, _, n, k, dep[N], fa[N][LOG], cnt, ans;
    vector<int> e[N], a;
    void dfs(int u) {
        dep[u] = dep[fa[u][0]] + 1;
        for (int i = 1; i < LOG; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int v : e[u]) {
            if (v == fa[u][0]) continue;
            fa[v][0] = u;
            dfs(v);
        }
    }
    int dis(int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);
        int ret = dep[x] - dep[y];
        for (int i = LOG - 1; ~i && dep[x] > dep[y]; i--) if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
        if (x == y) return ret;
        for (int i = LOG - 1; ~i; i--) {
            if (fa[x][i] ^ fa[y][i]) {
                ret += 1 << (i + 1);
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return ret + 2;
    }
    void main() {
        read(c, _);
        while (_--) {
            read(n, k);
            ans = n;
            for (int i = 1; i <= n; i++) e[i].clear();
            for (int i = 1, u, v; i < n; i++) {
                read(u, v);
                e[u].eb(v);
                e[v].eb(u);
            }
            dfs(1);
            if (c == 7) {
                for (int i = 1; i < n; i++) {
                    for (int j = i + 1; j <= n; j++) {
                        int mx = 0;
                        for (int k = 1; k <= n; k++) {
                            if (k == i || k == j) continue;
                            chkmax(mx, min(dis(i, k), dis(j, k)));
                            if (mx > ans) break;
                        }
                        chkmin(ans, mx);
                    }
                }
                writeln(ans);
                continue;
            }
            for (int i = 1; i < (1 << n); i++) {
                if (__builtin_popcount(i) ^ k) continue;
                int mx = 0;
                cnt = 0;
                a.clear();
                for (int j = 1; j <= n; j++) {
                    if (~i >> (j - 1) & 1) continue;
                    cnt++;
                    a.eb(j);
                    for (int l : e[j]) {
                        if (l > j) continue;
                        if (~i >> (l - 1) & 1) continue;
                        cnt--;
                    }
                }
                if (cnt > 2) continue;
                for (int j = 1; j <= n; j++) {
                    if (i >> (j - 1) & 1) continue;
                    int mn = n;
                    for (int l : a) {
                        chkmin(mn, dis(j, l));
                        if (mn < mx) break;
                    }
                    // printf("j = %lld, mn = %lld\n", j, mn);
                    chkmax(mx, mn);
                    if (mx > ans) break;
                }
                // printf("i = %lld, mx = %lld\n", i, mx);
                chkmin(ans, mx);
            }
            writeln(ans);
        }
    }
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    W_C_B_H::main();
    return 0;
}