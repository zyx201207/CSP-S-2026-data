// 我是坚固板 我是版固件 我是古板监 我是半间鼓 我是兼办股 我是固件办
// ** 的忘清空了 浪费时间！
#include<bits/stdc++.h>
using ll = long long; using ull = unsigned long long; using uint = unsigned int;
#define ld std::cin
#define jyt std::cout
#define cmd std::cerr
#define cprt(...) fprintf(stderr, __VA_ARGS__)
#define REQ(i, l, r) for (int i = l; i <  r; ++i)
#define REP(i, l, r) for (int i = l; i <= r; ++i)
#define PER(i, l, r) for (int i = l; i >= r; --i)
namespace JoKing { const int _L = 1 << 20; char _bf[_L], *_p1 = _bf, *_p2 = _bf;
#define gc() (_p1 == _p2 && (_p2 = (_p1 = _bf) + fread(_bf, 1, _L, stdin), _p1 == _p2) ? EOF : *_p1++)
inline ll ldr() { char ch = gc(); bool f = 0; ll x = 0; while (ch < '0' || '9' < ch) f = (ch == '-'), ch = gc(); while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + (ch & 15), ch = gc(); return f ? -x : +x; }
inline char ldc() { char ch = gc(); while (isspace(ch)) ch = gc(); return ch; }
#define eb emplace_back
#define mset(a, v, n) memset((a), (v), sizeof((a)[0]) * (n))
#define mcpy(a, b, n) memcpy((a), (b), sizeof((a)[0]) * (n))
const int N = 2e6 + 3; const ll inf = (ll)2e18 + 7; const uint P = 998244353; // <64mb <160ms
int OPT, n, nx[N]; ll D, x[N]; int c0[N], c1[N], cp[N];
void TerraFirmaGreg() { }
signed Create() {
    n = ldr(), D = ldr();
    REP(i, 1, n) x[i] = ldr(); // x[i] could <0
    int pt = 0; nx[n + 1] = n + 1;
    REP(i, 1, n) { while (pt < n && x[pt + 1] - x[i] <= D) ++pt; nx[i] = pt; }
    REP(i, 1, n) ++c0[i];
    ll Ans = 0;
    REP(i, 1, n) {
        int j = nx[i], k = nx[j]; if (i == j) continue;
        if (j - i == 1 || x[k] - x[j - 2] > D) {
            if (x[k] - x[j - 1] <= D) c1[j] += c0[i];
            else if (x[k - 1] - x[j - 1] <= D) cp[j] += c0[i] + cp[i], c1[j] += c1[i];
            else c0[j] += c0[i] + cp[i], c1[j] += c1[i];
        }
        int l = j + 1, r = std::min(n, k);
        if (l <= r) {
            Ans += (ll)c1[i] * std::max(0, r - std::max(nx[j - 1] + 1, l) + 1);
            if (j - i > 1) Ans += (ll)c0[i] * std::max(0, std::min(nx[j - 1], r) - std::max(nx[j - 2] + 1, l) + 1);
        }
    }
    jyt << Ans << '\n';
    return 0;
}
void FlyWheel() { mset(c0, 0, n + 1), mset(c1, 0, n + 1), mset(cp, 0, n + 1); } }
signed main() {
#ifndef WYY
//    freopen("obsidian.in", "r", stdin), freopen("obsidian.out", "w", stdout);
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
    JoKing::OPT = JoKing::ldr(); int TEST = JoKing::ldr(); JoKing::TerraFirmaGreg();
    while (TEST--) JoKing::Create(), JoKing::FlyWheel();
#ifdef WYY
    cmd << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}