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
const int N = 503, M = 5e5 + 3, Q = 1e5 + 3, MXD = 23; const uint P = 998244353; // <64mb <400ms
int OPT, n, m, D, q; ll w[M], f[N][N]; std::vector<std::pair<int, int> > G[M];
void TerraFirmaGreg() { }
signed Create() {
    OPT = ldr(), n = ldr(), m = ldr(), D = ldr(), q = ldr();
    REP(i, 1, m) w[i] = ldr();
    REP(u, 1, n) mset(f[u], 0x3f, n + 1), f[u][u] = 0;
    REP(i, 1, n) { int K = ldr(), x, t; while (K--) x = ldr(), t = ldr(), G[x].eb(i, t); }
    REP(ik, 1, m) {
        int ln = (int)G[ik].size();
        REQ(i, 0, ln) {
            auto [u, ut] = G[ik][i];
            REQ(j, i + 1, ln) {
                auto [v, vt] = G[ik][j];
                f[u][v] = std::min(f[u][v], (ll)ut + vt);
            }
        }
    }
    REP(u, 1, n) REP(v, u + 1, n) f[u][v] = f[v][u] = std::min(f[u][v], f[v][u]);
    REP(k, 1, n) REP(i, 1, n) REP(j, 1, n) f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
    REP(Ck, 1, q) {
        int s = ldr(), t = ldr(); ll _ = LLONG_MAX;
        for (auto [u, ut] : G[s]) for (auto [v, vt] : G[t])
            _ = std::min(_, (ll)ut + vt + f[u][v]);
        jyt << (_ + w[s] + w[t]) << '\n'; 
    }
    return 0;
}
void FlyWheel() { } }
signed main() {
#ifndef WYY
//    freopen("obsidian.in", "r", stdin), freopen("obsidian.out", "w", stdout);
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
    int TEST = 1; JoKing::TerraFirmaGreg();
    while (TEST--) JoKing::Create(), JoKing::FlyWheel();
#ifdef WYY
    cmd << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}