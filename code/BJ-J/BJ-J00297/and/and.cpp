#include <iostream>

using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' or ch > '9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' and ch <= '9') { x = (x << 3) + (x << 1) + (int)(ch ^ 48); ch = getchar(); }
    return x * f;
}

inline void write(int x) {
    char stk[20]; int top = 0;
    if (x < 0) { putchar('-'); x = -x; }
    do { stk[++top] = x % 10; x /= 10; } while (x);
    while (top) { putchar('0' + stk[top--]); }
}

const int maxn = 2e5 + 10;
const int maxb = 35;

bool c[maxb][maxn];
int n, m;
int a[maxn];

bool f[maxn];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read(); m = read();
    for (int i = 1; i <= n; i++) f[i] = true, a[i] = read();
    for (int b = 0; b <= 31; b++) {
        for (int i = 1; i <= n; i++) {
            c[b][i] = (a[i] >> b) & 1;
        }
    }
    int ans = 0;
    for (int b = 31; b >= 0; b--) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] and c[b][i]) cnt++;
        }
        if (cnt >= m) {
            ans += 1 << b;
            for (int i = 1; i <= n; i++) {
                if (!f[i] or !c[b][i]) f[i] = false;
            }
        }
    }

    write(ans);
    putchar('\n');

    return 0;
}
