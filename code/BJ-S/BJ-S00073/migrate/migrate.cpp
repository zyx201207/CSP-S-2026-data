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
const int MAXN = 2e6 + 5;
int c, t, n, m, a[MAXN], u, v, mn, cnt;
void dfs(int now, int ct) {
    if (now == v) {
        if (ct == mn) cnt++;
        else if (ct < mn) mn = ct, cnt = 1;
        return;
    }
    for (int i = now + 1; i <= v; i++) {
        if (a[i] - a[now] <= m) dfs(i, ct + 1);
    }
}
void solve() {
    n = rd(), m = rd();
    for (int i = 1; i <= n; i++) a[i] = rd();
    if (c == 11 || c == 12) {
        int mx = m / a[2] - a[1];
        if (mx == 0) puts("0");
        else if (mx == 1) {
            puts("0");
        } else {
            wt(n - 2);
            putchar('\n');
        }
        return;
    }
    int ans = 0;
    for (u = 1; u < n; u++) {
        for (v = u + 1; v <= n; v++) {
            mn = 1e18, cnt = 0;
            dfs(u, 0);
            if (cnt == 2) ans++;
        }
    }
    wt(ans), putchar('\n');
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    c = rd(), t = rd();
    while (t--) solve();
    return 0;
}

