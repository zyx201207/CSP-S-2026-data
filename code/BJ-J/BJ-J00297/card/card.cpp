#include <iostream>
#include <algorithm>
#include <cstring>

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

const int maxn = 5e5 + 10;
const int maxm = 3e5 + 10;

int a[maxn];
int now[maxm];
int lst[maxn];

int ans[maxm];
bool f[maxn];
bool g[maxm];

int n, m;

int main() {
freopen("card.in", "r", stdin);
freopen("card.out", "w", stdout);
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        lst[i] = now[a[i]];
        now[a[i]] = i;
    }

    for (int st = 1; st <= n; st++) {
        memset(f + st, 1, n - st + 1);
        memset(g + 1, 0, m);
        for (int i = st; i <= n; i++) {
            int k = i;
            do {
                if (k < st) {
                    k = -1;
                    break;
                }
                k = lst[k];
            } while (!f[k]);
            if (k == -1) continue;
            memset(f + k, 0, i - k);
        }
        for (int i = st; i <= n; i++) {
            if (f[i]) g[a[i]] = true;
        }
        for (int i = 1; i <= m; i++) {
            if (g[i]) ans[i]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
