// Time Limit : 3.0 s
// Memory Limit : 1024 MiB
/* --------------- Code Below --------------- */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
#define I inline
#define reg register
typedef pair<int, int> pint;
#define fi first
#define se second
#define mk make_pair

char BG;

namespace Input {
    char ibuf[(1<<21)+1], *p1 = ibuf, *p2 = ibuf;
    #define gh() (((p1==p2)&&(p2=(p1=ibuf)+fread(ibuf,1,1<<21,stdin)),p1==p2)?EOF:*p1++)
    template<typename T = int> T read() {
        T x = 0, sgn = 1;
        reg char c = gh();
        while (!isdigit(c)) (c=='-')&&(sgn=-1), c = gh();
        while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = gh();
        return x*sgn;
    }
}
using namespace Input;

constexpr int N = 1e6+5;

int cid, tid, T, n, K;
struct Edge { int to, next; } e[N<<1];
int head[N], cnt;
I void add(int u, int v) {
    e[cnt] = Edge{v, head[u]};
    head[u] = cnt++;
}

int d[N], mark[N], rt1, rt2;
vector<int> vec, lhs, rhs;
void DFS1(int u, int fa) {
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (v != fa && !mark[v]) { d[v] = d[u]+1; DFS1(v, u); }
    }
}
int up[N];
void DFS2(int u, int fa) {
    up[u] = fa;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (v != fa && !mark[v]) { d[v] = d[u]+1; DFS2(v, u); }
    }
}

int col[N];
void DFS3(int u, int fa, int c) {
    col[u] = c;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) DFS3(v, u, c);
    }
}

void GetDiameter(vector<int>& v, int u, int c) {
    d[u] = 0;
    DFS1(u, 0);
    int rt = 0, pos = 0;
    for (int i = 1; i <= n; i++)
        if ((!rt || d[rt] < d[i]) && col[i] == c) rt = i;
    d[rt] = up[rt] = 0;
    DFS2(rt, 0);
    for (int i = 1; i <= n; i++)
        if ((!pos || d[pos] < d[i]) && col[i] == c) pos = i;
    while (pos) {
        v.emplace_back(pos);
        pos = up[pos];
    }
}

int lim, tot, h[N];
void DFS(int u, int fa, int c) {
    h[u] = 0;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (v != fa && col[v] == c) {
            DFS(v, u, c);
            h[u] = max(h[u], h[v]+1);
        }
    }
    if (h[u] >= lim) ++tot;
}

bool check(int mid) {
    lim = mid;
    int x = (lhs.size()-1)/2, y = (rhs.size()-1)/2;
    for (int i = x-1; i <= x+1; i++) {
        if (i < 0 || i >= (int)lhs.size()) continue;
        for (int j = y-1; j <= y+1; j++) {
            if (j < 0 || j >= (int)rhs.size()) continue;
            tot = 0;
            DFS(lhs[i], 0, 1), DFS(rhs[j], 0, 2);
            if (tot <= K) return true;
        }
    }
    return false;
}

void init() {
    cnt = rt1 = rt2 = tot = lim = 0;
    for (int i = 0; i <= n; i++) head[i] = -1;
    for (int i = 0; i <= n; i++) d[i] = mark[i] = col[i] = 0;
    vec.clear(); lhs.clear(), rhs.clear();
}

void solve() {
    n = read(), K = read();
    init();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v), add(v, u);
    }
    if (K == n) return (void)printf("%d\n", 0);
    GetDiameter(vec, 1, 0);
    rt1 = vec[(vec.size()-1)/2], rt2 = vec[(vec.size()+1)/2];
    DFS3(rt1, rt2, 1); DFS3(rt2, rt1, 2);
    mark[rt2] = true;
    GetDiameter(lhs, rt1, 1);
    mark[rt2] = false, mark[rt1] = true;
    GetDiameter(rhs, rt2, 2);

    int L = 1, R = n;
    while (L < R) {
        int mid = (L+R)>>1;
        if (check(mid)) R = mid;
        else L = mid+1;
    }
    printf("%d\n", L);
}

char ED;

#define filename "hub"
int main() {
#ifdef filename
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
#endif

    fprintf(stderr, "[Static Memory : %.3lf MiB]\n", abs(&BG-&ED)/1024.0/1024.0);
    clock_t st = clock();

    cid = read(), T = read();
    while (T--) solve();

    clock_t ed = clock();
    fprintf(stderr, "[Time : %.3lf s]\n", (ed-st)/1000.0);

    return 0;
}
/*
Compile :
    g++ hub.cpp -o hub -std=c++14 -O2 -Wall "-Wl,--stack=998244353"
    ./hub

Expectation : ?? pts
----------------------------------------
[Static Memory : 40.147 MiB]
[Time : 0.000 s]
*/