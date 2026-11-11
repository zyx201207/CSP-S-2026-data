#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005];
int zhan[505][23], rod[500005][23];
int ans, used[500005];

int dfs(int x, int y, int tim, int lastr, int lastz) {
    if (x == y) {
		
        if (ans == 0)
            ans = tim;
        ans = min(ans, tim);
    }
    if (tim >= ans && ans != 0)
        return 0;
    for (int i = 1; i <= n; i++) {
        if (zhan[x][i] == 0 || i == lastr)
            continue;
        for (int j = 1; j <= m; j++) {
            if (rod[i][j] == 0)
                break;
            if (rod[i][j] == lastz)
				continue;
            dfs(rod[i][j], y, tim + zhan[x][i] + zhan[rod[i][j]][i], i, x);
        }
    }
    return 0;
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int cnt = 0;
        for (int j = 1; j <= k; j++){
            int a, b;
            cin >> a >> b;
            zhan[a][i] = b;
            rod[i][++cnt] = a;
        } 
    }
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        ans = 0;
        dfs(a, b, w[a] + w[b], 0, 0);
        cout << ans << '\n';
    }
    return 0;
}
