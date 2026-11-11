#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 522, M = 5e5 + 55;
int c, n, m, D, q, k[N], tot[M], num[22][M], ID[22][M], d[N][N], w[M];
vector<int> a[M], t[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for (int j = 1; j <= k[i]; j++) {
            int aa, tt;
            cin >> aa >> tt;
            a[i].push_back(aa);
            t[i].push_back(tt);
            tot[aa]++;
            ID[tot[aa]][aa] = i;
            num[tot[aa]][aa] = j;
        }
    }
    //for (int i = 1; i <= m; i++) cout << tot[i] << " ";
    //cout << "\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) d[i][j] = 1e18;
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int x = 1; x <= tot[i]; x++) {
            for (int y = 1; y <= tot[i]; y++) {
                if (x == y) continue;
                int ID1 = ID[x][i], ID2 = ID[y][i];
                int num1 = num[x][i], num2 = num[y][i];
                int w1 = t[ID1][num1], w2 = t[ID2][num2];
                d[ID1][ID2] = d[ID2][ID1] = w1 + w2;
            }
        }
    }
    for (int p = 1; p <= n; p++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
            }
        }
    }
    while (q--) {
        int x, y, ans = 1e18;
        cin >> x >> y;
        //cout << tot[x] << " " << tot[y] << "\n";
        for (int i = 1; i <= tot[x]; i++) {
            for (int j = 1; j <= tot[y]; j++) {
                int ID1 = ID[i][x], ID2 = ID[j][y];
                //cout << ID1 << " " << ID2 << "\n";
                ans = min(ans, w[x] + t[ID1][num[i][x]] + w[y] + t[ID2][num[j][y]] + d[ID1][ID2]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
