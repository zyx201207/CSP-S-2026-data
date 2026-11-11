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

constexpr int N = 5e5+5;

int n, rst;
i64 m, a[N];

char ED;

#define filename "crystal"
int main() {
#ifdef filename
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
#endif

    fprintf(stderr, "[Static Memory : %.3lf MiB]\n", abs(&BG-&ED)/1024.0/1024.0);
    clock_t st = clock();

    n = read(); m = read<i64>();
    for (int i = 1; i <= n; i++) a[i] = read<i64>();
    sort(a+1, a+n+1);
    i64 sum = 0;
    for (int i = 1, l = 1; i <= n; i++) {
        sum += (a[i]-a[i-1])*(i-l);
        while (l < i && sum > m) sum -= a[i]-a[l], ++l;
        rst = max(rst, i-l+1);
    }

    printf("%d", rst);

    clock_t ed = clock();
    fprintf(stderr, "[Time : %.3lf s]\n", (ed-st)/1000.0);

    return 0;
}
/*
Compile :
    g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall
    ./crystal
Compare :
    fc "D:\CQ-S00528\crystal1.out" "D:\CQ-S00528\crystal1.ans"
    fc "D:\CQ-S00528\crystal2.out" "D:\CQ-S00528\crystal2.ans"
    fc "D:\CQ-S00528\crystal3.out" "D:\CQ-S00528\crystal3.ans"
    fc "D:\CQ-S00528\crystal4.out" "D:\CQ-S00528\crystal4.ans"

Expectation : 100 pts
----------------------------------------
[Static Memory : 5.815 MiB]
[Time : 0.022 s]
*/