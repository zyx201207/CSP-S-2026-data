#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1000010;
typedef long long ll;
typedef pair<int, int> PII;
ll d[N][N];
int W[M];
vector<PII> s[M];
void chkmin(ll &x, ll y) { x = min(x, y); }
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cas, n, m, abc, Q;cin >> cas >> n >> m >> abc >> Q;
    for (int i = 1; i <= m; i ++ ) cin >> W[i];
    for (int i = 1; i <= n; i ++ ) {
        int k;cin >> k;
        while (k -- ) {
            int x, y;cin >> x >> y;
            s[x].push_back({i, y});
        }
    }
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i ++ ) d[i][i] = 0;
    for (int i = 1; i <= m; i ++ ) {
        int len = (int)s[i].size();
        for (int j = 0; j < len; j ++ ) for (int k = 0; k < len; k ++ )
            chkmin(d[s[i][j].first][s[i][k].first], s[i][j].second + s[i][k].second);
    }
    for (int k = 1; k <= n; k ++ ) for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= n; j ++ )
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while (Q -- ) {
        int x, y;cin >> x >> y;
        ll ans = 1e18;
        for (auto i : s[x]) for (auto j : s[y]) ans = min(ans, d[i.first][j.first] + i.second + j.second + W[x] + W[y]);
        cout << ans << '\n';
    }
    return 0;
}