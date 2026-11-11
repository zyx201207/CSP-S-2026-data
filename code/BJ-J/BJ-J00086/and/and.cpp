#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin)), *p1++)
char buf[1 << 20], *p1, *p2;
inline int rd() {
    int x = 0, f = 1;
    char c = gc();
    for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
    for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
    return x * f;
}
inline void wt(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) wt(x / 10);
    putchar(x % 10 + '0');
}
const int MAXN = 2e5 + 5;
int a[MAXN];
char c[MAXN];
bool ok[MAXN];
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    int n = rd(), m = rd();
    for (int i = 1; i <= n; i++) {
        a[i] = rd();
        ok[i] = 1;
    }
    int ans = 0;
    for (int bit = 30; bit >= 0; bit--) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (ok[i] && (a[i] >> bit & 1) == 1) cnt++;
        }
        if (cnt < m) continue;
        if (cnt == m) {
            int ans2 = -1;
            for (int i = 1; i <= n; i++) {
                if (ok[i] && (a[i] >> bit & 1) == 1) ans2 &= a[i];
            }
            wt(ans2);
            return 0;
        }
        ans += 1 << bit;
        for (int i = 1; i <= n; i++) {
            if (ok[i] && (a[i] >> bit & 1) == 0) ok[i] = 0;
        }
    }
    wt(ans);
    return 0;
}
