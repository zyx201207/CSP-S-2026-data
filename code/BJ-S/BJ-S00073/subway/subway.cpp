#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin)), *p1++)
char buf[1 << 20], *p1, *p2;
inline int rd() {
    int x = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
    for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
    return x * f;
}
inline void wt(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) wt(x / 10);
    putchar(x % 10 + '0');
}
const int MAXN = 505, MAXM = 1005;
int c, n, m, dd, q, k[MAXN], w[MAXM], d[MAXM][MAXM];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    int c = rd(), n = rd(), m = rd(), dd = rd(), q = rd();
    for (int i = 1; i <= m; i++) w[i] = rd();
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        k[i] = rd();
        int a = rd(), b = rd(), c = rd(), ddd = rd();
        d[a][c] = d[c][a] = min(d[a][c], b + ddd);
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while (q--) {
        int x = rd(), y = rd();
        wt(w[x] + w[y] + d[x][y]), putchar('\n');
    }
    return 0;
}

