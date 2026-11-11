#include <bits/stdc++.h>
#define int long long

using namespace std;

inline int read() {
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}

inline void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 200005, INF = 0x3f3f3f3f;

int cnt[32];
int a[N], vis[N], ans;
int topp[N];
string s[N];

void buttin_expection(int x) {
    string err;
    int m = x;
    while (x) {
        err += (x % 2 + '0');
        x /= 2;
    }
    s[m] = err;
    reverse(err.begin(), err.end());
}

signed main(void) {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n = read(), m = read();
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
        buttin_expection(a[i]);
    }
    if (n == m) {
        int sum = a[1];
        for (int i = 1; i <= n; i ++) sum = sum & a[i];
        write(sum);
        return 0;
    }
    for (int base = 31; base >= 1; base --) {
        for (int i = 1; i <= n; i ++) {
            if (topp[a[i]]) continue;
            if (a[i] >= pow(2, base - 1)) cnt[base] ++;
        }
        if (cnt[base] >= m) {
            for (int i = 1; i <= n; i ++) if (a[i] < pow(2, base - 1)) topp[a[i]] = 1;
            vis[base] = 1;
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (!topp[a[i]]) {
            if (!ans) ans = a[i];
            else ans = ans & a[i];
        }
    }
    write(ans);
    return 0;
}
