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
const int MAXN = 5e5 + 5;
int a[MAXN];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    int n = rd(), m = rd();
    for (int i = 1; i <= n; i++) a[i] = rd();
    if (n == 1) { putchar('1'); return 0; }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++) {
        m -= (i - 1) * (a[i] - a[i - 1]);
        if (m <= 0) {
            while (a[i + 1] == a[i]) i++;
            wt(m == 0 ? i : i - 1);
            return 0;
        }
    }
    return 0;
}
