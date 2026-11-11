#include <bits/stdc++.h>
// #define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rloop(i, a, b) for(omt i = (a) ; i >= (b) ; i--)
#define chkmax(x, y) ((x) = max((x), (y)))
#define chkmin(x, y) ((x) = min((x), (y)))
#define mid (((l) + (r)) / 2)
#define lowbit ((x) & (-(x)))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 5e2 + 5;
const int M = 5e5 + 5;
const int D = 21;
int c, n, m, d, q, w[M], k;
ll a[N][N];
vector<int> id[M], t[M];
void build() {
    memset(a, 0x3f, sizeof(a));
    loop(i, 1, n) a[i][i] = 0;
    loop(i, 1, m) {
        int cnt = id[i].size();
        loop(j, 0, cnt - 1) loop(k, j + 1, cnt - 1) {
            int u = id[i][j], v = id[i][k], w = t[i][j] + t[i][k];
            chkmin(a[u][v], ll(w)), chkmin(a[v][u], ll(w));
        }
    }
}
void floyd() {
    loop(k, 1, n) loop(i, 1, n) loop(j, 1, n) chkmin(a[i][j], a[i][k] + a[k][j]);
}
void solve() {
    cin >> c >> n >> m >> d >> q;
    loop(i, 1, m) cin >> w[i];
    loop(i, 1, n) {
        int k; cin >> k;
        loop(j, 1, k) {
            int x, y; cin >> x >> y;
            id[x].push_back(i);
            t[x].push_back(y);
        }
    }
    build();
    floyd();
    while(q--) {
        int x, y; cin >> x >> y;
        ll ans = 0x3f3f3f3f3f3f3f3fll;
        loop(i, 0, int(id[x].size()) - 1) loop(j, 0, int(id[y].size()) - 1) {
            int u = id[x][i], v = id[y][j];
            chkmin(ans, t[x][i] + t[y][j] + a[u][v]);
        }
        cout << ans + w[x] + w[y] << '\n';
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}