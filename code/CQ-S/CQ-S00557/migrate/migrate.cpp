#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 5;
int n;
LL d, x[N];
int jump[N], f[N], g[N];
LL dp[N];
inline void read(int& x) {
    x = 0;char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
inline void read(LL& x) {
    x = 0;char c = getchar();
    bool neg = false;
    while (c < '0' || c > '9') {
        if (c == '-') neg = true;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    if (neg) x = -x;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int testcase, T;read(testcase), read(T);
    while (T--) {
        for (int i = 1;i <= n;++i) f[i] = g[i] = dp[i] = 0;
        read(n), read(d);
        for (int i = 1;i <= n;++i) read(x[i]);
        jump[n] = n;
        for (int i = n - 1;i >= 1;--i) {
            jump[i] = jump[i + 1];
            while (x[jump[i]] - x[i] > d) --jump[i];
            // printf("jump[%d] = %d\n", i, jump[i]);
        }
        for (int i = n - 1;i >= 1;--i) {
            for (int j = max(jump[i - 1] + 1, i + 1);j < jump[i];++j) ++f[i];
            if (jump[i] != jump[i - 1]) f[i] += f[jump[i]] + 1;
        }
        for (int i = 1;i <= n;++i)
            if (jump[i] > i) {
                ++g[jump[i]];
                if (jump[i] > jump[i - 1]) g[jump[i]] += g[i];
            }
        // for (int i = 1;i <= n;++i) printf("%d f %d g %d\n", i, f[i], g[i]);
        LL ans = 0;
        for (int i = n;i >= 1;--i)
            if (jump[i] > i) {
                ans += dp[jump[i]];
                if (jump[i - 1] < jump[i] - 1) ans += g[i] * dp[jump[i]];
                for (int j = max(jump[i - 2] + 1, i + 1);j <= jump[i - 1];++j) ++dp[i];
                if (jump[i] == jump[i - 1] && jump[i - 2] < jump[i - 1]) dp[i] += f[jump[i]];
                // printf("dp[%d] = %lld\n", i, dp[i]);
            }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/