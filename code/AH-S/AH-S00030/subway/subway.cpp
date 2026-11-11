#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 510;
const int MAXM = 500010;
const int MAXD = 25;
const int INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
int w[MAXM];
int k[MAXN];
int a[MAXN][MAXD], t[MAXN][MAXD];

int x, y;

int ans;

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

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        k[i] = read();
        for (int j = 1; j <= k[i]; j++) a[i][j] = read(), t[i][j] = read();
    }

    while (q --) {
        x = read(), y = read();

        cout << w[x] + t[1][x] + t[1][y] + w[y] << '\n';
    }
    return 0;
}
