#include <bits/stdc++.h>
using namespace std;
    
int rd() {
    int s = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        s = (s << 3) + (s << 1) + c - '0';
        c = getchar();
    }
    return s * f;
}

typedef long long ll;
const int N = 510;
const int M = 5e5 + 10;
const int D = 22;
const ll I = 1e18 + 10;

int _c, n, m, _d, q;
int w[M], d[M];
int p[M][N], t[M][N];
ll ds[N][N];

void floyd() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    _c = rd(), n = rd(), m = rd(), _d = rd(), q = rd();
    for (int i = 1; i <= m; i++) w[i] = rd();
    for (int i = 1; i <= n; i++) {
        int k = rd();
        for (int j = 1; j <= k; j++) {
            int xp = rd(), xt = rd();
            int x = ++d[xp];
            p[xp][x] = i, t[xp][x] = xt;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ds[i][j] = I;
        ds[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d[i]; j++) {
            for (int k = 1; k < j; k++) {
                int u = p[i][j], v = p[i][k];
                ds[u][v] = ds[v][u] = min(ds[u][v], (ll)(t[i][j] + t[i][k]));
            }
        }
    }
    floyd();
    while (q--) {
        int x = rd(), y = rd();
        ll ans = I, nt = w[x] + w[y];
        for (int i = 1; i <= d[x]; i++) {
            for (int j = 1; j <= d[y]; j++) {
                int u = p[x][i], v = p[y][j];
                ans = min(ans, nt + t[x][i] + t[y][j] + ds[u][v]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
g++ subway.cpp -o1 -fsanitize=leak,address,undefined
./1
diff subway.out subway.ans1
*/