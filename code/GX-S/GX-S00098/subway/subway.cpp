#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 600;
int c, n, m, d, q, tot;
long long f[maxn][maxn];
const long long INF = 1000;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    tot = m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        f[i][++tot] = x;
        f[tot][i] = x;
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int last = 0;
        for (int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            f[m + x][++tot] = y;
            f[tot][m + x] = y;
            f[last][tot] = -1;
            f[tot][last] = -1;
            last = tot;
        }
    }
	for (int i = 1; i <= tot; i++) {
		for (int j = 1; j <= tot; j++) {
            if (f[i][j] == 0) f[i][j] = INF;
            if (f[i][j] == -1) f[i][j] = 0;
		}
	}
    for (int k = 1; k <= tot; k++) {
        for (int i = 1; i <= tot; i++) {
            for (int j = 1; j <= tot; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << f[y][x] << endl;
    }
    return 0;
}
