#include <iostream>

using namespace std;

#define ll long long

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

int a[maxn];
char c[maxn];

ll pre[maxn], suf[maxn];

int n;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    n = read();
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read(); tot += a[i];
        c[i] = getchar();
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (ll)a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + (ll)a[i];
    }

    int l = 1, r = n;
    ll ans = 0;
    ll pos = min(pre[l], suf[r]);
    if (c[l] != c[r]) ans += pos;
    while (pre[l] + suf[r] <= tot) {
        if (pre[l] > pos) {
            r--;
            pos = min(pre[l], suf[r]);
            if (pos + pos > tot) break;
            if (c[l] != c[r]) ans += pos - suf[r + 1];
        } else if (suf[r] > pos) {
            l++;
            pos = min(pre[l], suf[r]);
            if (pos + pos > tot) break;
            if (c[l] != c[r]) ans += pos - pre[l - 1];
        } else {
            l++, r--;
            pos = min(pre[l], suf[r]);
            if (pos + pos > tot) break;
            if (c[l] != c[r]) ans += pos - pre[l - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
