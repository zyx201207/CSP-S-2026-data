// 我是坚固板 我是版固件 我是古板监 我是半间鼓 我是兼办股 我是固件办
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
const int N = 5e5 + 3, inf = 1e9 + 7; const uint P = 998244353; //
int n; ll m, a[N];
void TerraFirmaGreg() { }
signed Create() {
    n = ldr(), m = ldr();
    REP(i, 1, n) a[i] = ldr();
    std::sort(a + 1, a + n + 1);
    ll S = 0; int pt = 1, Ans = 0; 
    REP(i, 1, n) {
        S += (ll)(a[i] - a[i - 1]) * (i - pt);
        while (pt < i && S > m) S -= a[i] - a[pt], ++pt;
        Ans = std::max(Ans, i - pt + 1); 
    }
    jyt << Ans << '\n';
    return 0;
}
void FlyWheel() { } }
signed main() {
#ifndef WYY
//    freopen("obsidian.in", "r", stdin), freopen("obsidian.out", "w", stdout);
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
    int TEST = 1; JoKing::TerraFirmaGreg();
    while (TEST--) JoKing::Create(), JoKing::FlyWheel();
#ifdef WYY
    cmd << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}