#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 500010;

int n, m;
int a[MAXN];

int d[MAXN];
int p[MAXN];

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || '9' < c) {
        if (c == EOF) return 0;
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int Cnt(int idx, int x) {
    int cnt = 0;
    int rest = m;
    for (int i = idx; i >= 1; i--) {
        if (rest >= x - a[i]) {
            ++ cnt;
            rest -= x - a[i];
        }
        else break;
    }
    return cnt;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();

    sort(a + 1, a + 1 + n);
    if (n <= 5000) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, Cnt(i, a[i]));
        }
        cout << ans << '\n';
    }
    else {
        for (int i = 2; i <= n; i++) d[i] = a[i] - a[i - 1]; // d[i] : a[i] - a[i - 1]
        for (int i = 2; i <= n; i++) p[i] = p[i - 1] + d[i]; // p[i] : The sum of d[1] ~ d[i]

        int ans = 0;
        int l = 1;
        int s = 0;
        for (int r = 2; r <= n; r++) {
            s += d[r] * (r - l);
            while (s > m) {
                s -= (p[r] - p[l - 1]);
                ++ l;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
