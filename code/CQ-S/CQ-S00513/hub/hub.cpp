// 我是坚固板 我是版固件 我是古板监 我是半间鼓 我是兼办股 我是固件办
// 这啥大样例啊 乱写都能全过吧 全给特殊性质和小数据是谁教你的。
// 怎么又变成几年前的样子 这不挂我吃 我时间应该不够写暴力了 写上拍子也没时间调了。
// ***** ***** ** 出题人 摆烂了。
// 你最好别每个 TEST 放 若干组正确性 hack
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
const int N = 1e6 + 3, inf = 1e9 + 7; const uint P = 998244353; // <???ms <???mb Expected: 20~100pts
int OPT, n, K, V; std::vector<int> G[N];
int fa[N], Fx, Fd, S, T, D, Rt;
void fd(int x, int p, int D) {
    if (fa[x] = p, Fd < D) Fx = x, Fd = D;
    for (int v : G[x]) if (v ^ p) fd(v, x, D + 1);
}
int mx[N], vs[N], dep[N];
void pwk(int x, int p) { 
    fa[x] = p, mx[x] = 0, vs[x] = (x == S || x == T), dep[x] = dep[p] + 1;
    for (int v : G[x]) if (v ^ p)
        pwk(v, x), mx[x] = std::max(mx[x], mx[v] + 1), vs[x] |= vs[v];
    std::sort(G[x].begin(), G[x].end(), [&](int A, int B) { return (A == p || vs[A] ? -1 : mx[A]) > (B == p || vs[B] ? -1 : mx[B]); });
}
int p[N], TRt, f[N], g[N], w[N];
void fwk(int x, int p) {
    f[x] = (mx[x] >= V);
    for (int v : G[x]) if (v ^ p)
        fwk(v, x), f[x] += f[v];
}
int nx[N][20], nw[N][20], tdp[N];
void gwk(int x, int p) {
    g[x] = f[x] + (mx[x] < V), nx[x][0] = p, nw[x][0] = w[p], tdp[x] = tdp[p] + 1;
    int LG = std::__lg(tdp[x]), tx = x; 
    REP(d, 1, LG) nx[x][d] = nx[nx[x][d - 1]][d - 1], nw[x][d] = std::max(nw[x][d - 1], nw[nx[x][d - 1]][d - 1]);
    PER(d, LG, 0) if (tx ^ TRt && d <= std::__lg(tdp[tx]) && nw[tx][d] <= V - dep[x]) tx = nx[tx][d]; 
    if (tx == TRt) {
        g[tx] = std::min(g[tx], 1 + g[x]);
    } else {
        tx = fa[tx], g[tx] = std::min(g[tx], f[tx] + g[x]);
    }
    for (int v : G[x]) if (v ^ p) {
        w[x] = (G[x][0] == v ? ((int)G[x].size() < 2 || G[x][1] == fa[x] || vs[G[x][1]] ? 0 : mx[G[x][1]] + 1) : mx[G[x][0]] + 1) - dep[x];
        f[x] -= f[v], gwk(v, x), g[x] = std::min(g[x], f[x] + g[v]), f[x] += f[v];
    }
}
int f1[N], f2[N], stL[20][N], stR[20][N];
int rmqL(int l, int r) {
    int LG = std::__lg(r - l + 1);
    return std::max(stL[LG][l], stL[LG][r - (1 << LG) + 1]) - l + 1;
}
int rmqR(int l, int r) {
    int LG = std::__lg(r - l + 1);
    return std::max(stR[LG][l], stR[LG][r - (1 << LG) + 1]) + r + 1;
}
bool chk() {
    int u = S, v = T;
    REP(d, 1, V) u = fa[u], v = fa[v];
    int L = D + 1 - V - V, tu = u, tv = v, pu = 1, pv = L;
    while (tu) p[pu++] = tu, tu = fa[tu];
    while (tv ^ Rt) p[pv--] = tv, tv = fa[tv];
    mset(f, 0, n + 1), mset(g, 0, n + 1);
    int tsz = 2, D = 0; f[u] = f[v] = 1;
    REQ(i, 2, L) {
        int x = (TRt = p[i]); f[x] = 1;
        for (int v : G[x]) if (!vs[v]) fwk(v, x), f[x] += f[v];
        g[x] = f[x], nx[x][0] = 0, nw[x][0] = inf, tdp[x] = 0;
        for (int v : G[x]) if (!vs[v]) {
            w[x] = (G[x][0] == v ? ((int)G[x].size() < 2 || G[x][1] == fa[x] || vs[G[x][1]] ? 0 : mx[G[x][1]] + 1) : mx[G[x][0]] + 1) - dep[x];
            f[x] -= f[v], gwk(v, x), g[x] = std::min(g[x], f[x] + g[v]), f[x] += f[v];
        }
        tsz += f[x], D = std::max(D, f[x] - g[x]);
    }
    // P1 u,v 相连
    if (tsz - D <= K) return 1;
    f1[0] = f2[L + 1] = 0;
    REP(i, 1, L) f1[i] = f1[i - 1] + f[p[i]];
    PER(i, L, 1) f2[i] = f2[i + 1] + f[p[i]];
    REQ(i, 2, L) {
        int x = (TRt = p[i]);
        int t = (G[x][0] == fa[x] || vs[G[x][0]] ? 0 : mx[G[x][0]] + 1);
        stL[0][i] = t + i, stR[0][i] = t - i;
    }
    REQ(i, 1, 19) REP(j, 1, L - (1 << i) + 1) {
        stL[i][j] = std::max(stL[i - 1][j], stL[i - 1][j + (1 << (i - 1))]);
        stR[i][j] = std::max(stR[i - 1][j], stR[i - 1][j + (1 << (i - 1))]);
    }
    int pt = 2;
    REQ(i, 2, L) {
        while (pt <= i && std::max(rmqL(pt, (i + pt) >> 1), rmqR((i + pt + 1) >> 1, i)) > V) ++pt;
        if (pt <= i && f1[pt - 1] + f2[i + 1] <= K) return 1;
    }
    return 0;
}
void TerraFirmaGreg() { }
signed Create() {
    n = ldr(), K = ldr();
    REP(i, 2, n) { int u = ldr(), v = ldr(); G[u].eb(v), G[v].eb(u); }
    if (n == K) return jyt << 0 << '\n', 0;
    Fx = Fd = -1, fd(1, 0, 0), S = Fx;
    Fx = Fd = -1, fd(S, 0, 0), T = Fx, D = Fd, Rt = T;
    { REP(d, 1, (D >> 1)) Rt = fa[Rt]; Fx = Fd = -1, pwk(Rt, 0); }
    int l = 1, r = ((D + 1) >> 1) - 1, rs = ((D + 1) >> 1); // 放置一个点在径心上 一定合法
    for (int md = (l + r) >> 1; l <= r; md = (l + r) >> 1)
        if (V = md, chk()) r = md - 1, rs = md; else l = md + 1;
    jyt << rs << '\n';
    return 0;
}
void FlyWheel() {  
    REP(x, 1, n) G[x].clear();
    mset(vs, 0, n + 1);
} }
signed main() {
#ifndef WYY
//    freopen("obsidian.in", "r", stdin), freopen("obsidian.out", "w", stdout);
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
    JoKing::OPT = JoKing::ldr(); int TEST = JoKing::ldr(); JoKing::TerraFirmaGreg();
    while (TEST--) JoKing::Create(), JoKing::FlyWheel();
#ifdef WYY
    cmd << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}
/*
是一个前 k 大的形式。
一定是最大通勤距离由叶子取到？不一定一条链两端点。
只有一个连通块就是换根+求 mxdep 的第 k+1 大，变化量 o(1) 用对顶堆就能维护。
否则如果暴力枚举 u,v 的话就是两个子树归并出的前 k 大和 u,v 之间的最远点取 max.
这个复杂度也太劣了 O(n^2log) 只有 50 分？
考虑定 u 了之后如果 v 不在最远点所在子树一定不优秀？不一定。
有很关键的一个点定 u 为根以后每个结点的权值全部确定了就是 mxdep[x]
难点：两个连通块中间部分的 d(i) 是到两个联通块 d(i) 的 min 而且两个连通块共用 k 的限制。
枚举中间部分最短路的分界边断开？钦定左/右两侧的点独立计算贡献。
还是二分全局答案 V。
定直径中心为根然后从叶子开始直接贪心就行了哈。
对！两个直径端点的 V 级祖先选择一定不劣且必须选择，选择后就得到必定分别位于两个连通块中的两个点。
其实不一定是分别位于两个连通块中。 算是知道为什么有多测了
分讨一下：第一种是直接把 u,v 狂暴连接。
分裂成若干独立子树。
考虑 dp 出让一个子树最远点 <=V 的单连通块花费 f/双连通块花费 g，那么选取 f-g 最大的就可以快速 chk。
否则 u,v 狂暴不连接。注意 u,v 是对称的。之前 dp 出的 f 还是有用的。
那么就是区间贡献。
一个合法的不选区间 [l,r] 是双单调的，可以双指针。
然后添加前后缀贡献就行了。
这个似乎是单 log 的我哭死。1h30min 还剩 写！
懒得写单 log 个就写双 log 看着并不慢的样子。
*/