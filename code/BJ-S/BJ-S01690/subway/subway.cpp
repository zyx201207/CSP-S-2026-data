#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2147483647;
int c, n, m, d, q, ans, x, y;
int w[500007], k[507], a[507][500007], t[507][500007];
int aa[500007][21], kk[500007];
int dis[507];



void bfs(int xx, int now) {
    for (int z = 1; z <= kk[xx]; z++) {
        int i = aa[xx][z];
        if (!dis[i]) {
            dis[i] = 1;
            for (int j = 1; j <= k[i]; j++) {
                if (a[i][j] == xx) {
                    now += t[i][j];
                }
                if (a[i][j] == y) {
                    now += w[y] + t[i][j];
                    ans = min(ans, now);
                    return ;
                }
                if (a[i][j] != xx) {
                    bfs(a[i][j], now+t[i][j]);
                }
            }
        }
    }
    return ;
}


int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            aa[a[i][j]][++kk[a[i][j]]] = i;
        }
    }
    for (int r = 1; r <= q; r++) {
        
        cin >> x >> y;
        memset(dis, 0, sizeof(dis));
        ans = MAXN;
        bfs(x, w[x]);
        cout << ans << endl;
    }

    return 0;
}