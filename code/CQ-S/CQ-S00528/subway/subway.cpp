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

constexpr int N = 505, M = 5e5+5;
constexpr i64 INF = 0x3f3f3f3f3f3f3f3fll;

int cid, n, m, D, Q, w[M];

i64 d[N][N];
vector<pair<int, int>> tram[M];

void shortestPath() {
    __builtin_memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (int)tram[i].size(); j++) {
            for (int k = j+1; k < (int)tram[i].size(); k++) {
                int x = tram[i][j].fi, y = tram[i][k].fi;
                d[x][y] = min(d[x][y], (i64)tram[i][j].se+tram[i][k].se);
                d[y][x] = min(d[y][x], (i64)tram[i][j].se+tram[i][k].se);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

char ED;

#define filename "subway"
int main() {
#ifdef filename
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
#endif

    fprintf(stderr, "[Static Memory : %.3lf MiB]\n", abs(&BG-&ED)/1024.0/1024.0);
    clock_t st = clock();

    cid = read(), n = read(), m = read(), D = read(), Q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        int k = read();
        for (int j = 1; j <= k; j++) {
            int x = read(), t = read();
            tram[x].emplace_back(i, t);
        }
    }
    shortestPath();
    while (Q--) {
        int x = read(), y = read();
        i64 rst = INF;
        for (int i = 0; i < (int)tram[x].size(); i++) {
            for (int j = 0; j < (int)tram[y].size(); j++) {
                int u = tram[x][i].fi, v = tram[y][j].fi;
                i64 now = d[u][v]+tram[x][i].se+tram[y][j].se+w[x]+w[y];
                rst = min(rst, now);
            }
        }
        printf("%lld\n", rst);
    }

    clock_t ed = clock();
    fprintf(stderr, "[Time : %.3lf s]\n", (ed-st)/1000.0);

    return 0;
}
/*
Compile :
    g++ subway.cpp -o subway -std=c++14 -O2 -Wall
    ./subway
Compare :
    fc "D:\CQ-S00528\subway1.out" "D:\CQ-S00528\subway1.ans"
    fc "D:\CQ-S00528\subway2.out" "D:\CQ-S00528\subway2.ans"
    fc "D:\CQ-S00528\subway3.out" "D:\CQ-S00528\subway3.ans"
    fc "D:\CQ-S00528\subway4.out" "D:\CQ-S00528\subway4.ans"
    fc "D:\CQ-S00528\subway5.out" "D:\CQ-S00528\subway5.ans"
    fc "D:\CQ-S00528\subway6.out" "D:\CQ-S00528\subway6.ans"
    fc "D:\CQ-S00528\subway7.out" "D:\CQ-S00528\subway7.ans"

Expectation : 100 pts
----------------------------------------
[Static Memory : 17.297 MiB]
[Time : 0.130 s]
*/