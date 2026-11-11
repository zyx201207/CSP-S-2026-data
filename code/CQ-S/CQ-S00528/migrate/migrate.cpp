// Time Limit : 1.0 s
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

constexpr int N = 2e6+5;

int cid, T, n, L[N], R[N];
i64 D, pos[N], f[N], g[N], tmp[N], rst;

void init() {
    pos[0] = LONG_LONG_MIN, pos[n+1] = LONG_LONG_MAX;
    L[n+1] = n+1;
    for (int i = 0; i <= n+1; i++) f[i] = g[i] = 0;
    rst = 0;
}

void solve() {
    n = read(), D = read<i64>();
    init();
    for (int i = 1; i <= n; i++) pos[i] = read<i64>();
    for (int i = 1; i <= n; i++) {
        L[i] = lower_bound(pos+1, pos+i+1, pos[i]-D)-pos;
        R[i] = upper_bound(pos+i, pos+n+2, pos[i]+D)-pos-1;
    }
    for (int i = 1; i <= n; i++) {
        if (R[i] > i && L[R[i]] == i) f[R[i]] += f[i];
        ++f[i];
        if (R[i] > i) f[R[i]]++;
    }
    for (int i = n; i >= 1; i--) {
        if (L[i] < i && R[L[i]] == i) g[L[i]] += g[i];
        ++g[i];
        if (L[i] < i) g[L[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        int x = R[i]-1, y = R[R[i]];
        if (x > i && L[x] == i && L[y] == x) {
            rst += f[i]*g[y];
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = R[i]-2, y = R[i]-1, z = R[i];
        if (x < i || L[y] != i) continue;
        int l = R[x]+1, r = R[y];
        if (r == R[z]) --r;
        if (l <= r) rst += (r-l+1)*f[i];
    }
    for (int i = 1; i <= n; i++) {
        int x = L[i]+2, y = L[i]+1, z = L[i];
        if (x > i || R[y] != i) continue;
        int l = L[y], r = L[x]-1;
        if (l == L[z]) ++l;
        if (l <= r) rst += (r-l+1)*g[i];
    }
    for (int i = 1; i <= n; i++) {
        int x = R[i]-2, y = R[i]-1, z = R[i];
        if (x < i || L[y] == i) continue;
        int l = R[x]+1, r = R[y];
        if (r == R[z]) --r;
        if (l <= r) rst += r-l+1;
    }
    printf("%lld\n", rst);
}

char ED;

#define filename "migrate"
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
    g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall
    ./migrate
Compare :
    fc "D:\CQ-S00528\migrate1.out" "D:\CQ-S00528\migrate1.ans"
    fc "D:\CQ-S00528\migrate2.out" "D:\CQ-S00528\migrate2.ans"
    fc "D:\CQ-S00528\migrate3.out" "D:\CQ-S00528\migrate3.ans"
    fc "D:\CQ-S00528\migrate4.out" "D:\CQ-S00528\migrate4.ans"
    fc "D:\CQ-S00528\migrate5.out" "D:\CQ-S00528\migrate5.ans"
    fc "D:\CQ-S00528\migrate6.out" "D:\CQ-S00528\migrate6.ans"

Expectation : 100 pts
----------------------------------------
[Static Memory : 78.294 MiB]
[Time : 0.022 s]
*/