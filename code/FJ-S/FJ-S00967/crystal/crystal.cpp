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
    const int N = 500005;
    int n, m, a[N], sum[N], ans = 1;
    void main() {
        read(n, m);
        for (int i = 1; i <= n; i++) read(a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
        for (int l = 1, r = 1; r <= n; r++) {
            for (; l <= r && (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) > m; l++);
            chkmax(ans, r - l + 1);
        }
        writeln(ans);
    }
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    W_C_B_H::main();
    return 0;
}
/*
14:42 打完缺省源和 ~/.bashrc
14:49 通过全部大样例
密码：Oct31==Dec25?
全国统一评测时采用的机器配置为：Intel Core Ultra 9 285K CPU @ 3.70 GHz (关闭睿频与能效核)，内存 96 GB。上述时限以此配置为准。
*/