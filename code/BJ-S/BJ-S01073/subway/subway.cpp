#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 5, N = 505;
int c, n, m, dd, q, w[M], d[N][N];
vector<pair<int, int> > l[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &dd, &q);
    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    memset(d, 0x1f, sizeof(d));
    for(int i = 1; i <= n; i++) {
        d[i][i] = 0; int k;
        scanf("%lld", &k);
        for(int j = 1; j <= k; j++) {
            int x, y; scanf("%lld %lld", &x, &y);
            l[x].push_back({i, y});
        }
    }
    for(int i = 1; i <= m; i++)
        for(int j = 0; j < l[i].size(); j++)
                for(int k = j + 1; k < l[i].size(); k++) {
                    d[l[i][j].first][l[i][k].first] =
                        min(d[l[i][j].first][l[i][k].first], l[i][j].second + l[i][k].second);
                    d[l[i][k].first][l[i][j].first] =
                        min(d[l[i][k].first][l[i][j].first], l[i][j].second + l[i][k].second);
                }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while(q--) {
        int x, y, ans = 4e18; scanf("%lld %lld", &x, &y);
        for(int i = 0; i < l[x].size(); i++)
            for(int j = 0; j < l[y].size(); j++)
                ans = min(ans, d[l[x][i].first][l[y][j].first] + l[x][i].second + l[y][j].second);
        printf("%lld\n", ans + w[x] + w[y]);
    }
}

