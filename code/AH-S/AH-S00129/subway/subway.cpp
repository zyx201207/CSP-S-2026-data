#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500005], t[500005][25];
vector <int> a[500005];
int s[25][25];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(s, 0x3f, sizeof(s));
    for (int i = 1; i <= n; i++)
        s[i][i] = 0;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int b;
            cin >> b;
            cin >> t[b][i];
            for (int l = 0; l < a[b].size(); l++)
                s[i][a[b][l]] = s[a[b][l]][i] = min(s[a[b][l]][i], t[b][i] + t[b][a[b][l]]);
            a[b].push_back(i);
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                s[i][j] = min(s[i][j], s[i][k] + s[k][j]);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        int ans = 1e12;
        for (int b = 0; b < a[x].size(); b++)
            for (int e = 0; e < a[y].size(); e++) {
                ans = min(ans, t[x][a[x][b]] + s[a[x][b]][a[y][e]] + t[y][a[y][e]]);
            }
        ans += w[x] + w[y];
        cout << ans << endl;
    }
    return 0;
}
