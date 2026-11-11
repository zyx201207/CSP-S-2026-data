#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
const int M = 1e3+10;
struct node{
    ll a, t;
};
ll c, n, m, d, q;
ll w[M];
vector <node> r[M];
ll remember[M][M];
bool vis[M];
ll dfs(ll x, ll y) {
    if (x == y) {
        return 0;
    }
    ll ans = 0x3f3f3f3f;
    for (ll i = 1; i <= n; i++) {
        ll ansn = 0x3f3f3f3f;
        ll tx = 0;
        bool b = 0;
        for (ll j = 0; j < r[i].size(); j++) {
            if (r[i][j].a == x) {
                b = 1;
                tx += r[i][j].t;
                break;
            }
        }
        if (!b) {
            continue;
        }
        for (ll j = 0; j <r[i].size(); j++) {
            ll txx = tx;
            if (!vis[r[i][j].a]) {
                vis[r[i][j].a] = 1;
                if (remember[r[i][j].a][y] != -1) {
                    txx += r[i][j].t + remember[r[i][j].a][y];
                }else{
                    int d = dfs(r[i][j].a, y);
                    if (d == -1) {
                        continue;
                    }
                    txx += r[i][j].t + d;
                    remember[x][y] = txx;
                    remember[y][x] = txx;
                }
                remember[x][y] = min(remember[x][y],txx);
                //cout << "rem" << x << ' ' << y << ' ' << remember[x][y] << endl;
                remember[y][x] = min(remember[y][x],txx);
                ansn = min(txx, ansn);
                vis[r[i][j].a] = 0;
            }
        }
        ans = min(ans, ansn);
    }
    if (ans >= 0x3f3f3f3f) {
        return -1;
    }
    return ans;
}
int main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(remember, -1, sizeof(remember));
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            ll a,t;
            cin >> a >> t;
            node s;
            s.a = a;
            s.t = t;
            r[i].push_back(s);
        }
    }
    for (int i = 1; i <= q; i++) {
        memset(vis, 0, sizeof(vis));
        int x, y;
        cin >> x >> y;
        if (x < y) {
            swap(x, y);
        }
        int t = 0;
        t += w[x] + w[y];
        vis[x] = 1;
        cout << t + dfs(x, y)<< endl;
    }
    return 0;
}