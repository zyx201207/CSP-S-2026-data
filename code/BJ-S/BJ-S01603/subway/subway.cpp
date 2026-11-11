#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN = 505, MAXM = 5e5 + 5;
ll c, n, m, d, q;
ll w[MAXM];
ll k[MAXN];
vector <pair <ll, ll>> way[MAXM];
ll f[MAXN][MAXN];
void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    return ;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        f[i][i] = 0;
        for(int j = 1; j <= k[i]; j++) {
            ll x, y;
            cin >> x >> y;
            way[x].push_back({i, y});
        }
    }
    for(int i = 1; i <= m; i++) {
        if(way[i].size() <= 1)
            continue;
        for(int j = 0; j < way[i].size(); j++) {
            for(int k = j + 1; k < way[i].size(); k++) {
                ll u = way[i][j].first, v = way[i][k].first, w = way[i][j].second + way[i][k].second;
                f[u][v] = f[v][u] = min(f[u][v], w);
            }
        }
    }
    floyd();
    ll x, y;
    while(q--) {
        cin >> x >> y;
        ll ans = 1e18;
        for(pair <ll, ll> i:way[x]) {
            for(pair <ll, ll> j:way[y]) {
                // cout << i.first << " " << j.first << " : " << f[i.first][j.first] << "\n";
                ans = min(ans, f[i.first][j.first] + i.second + j.second);
            } 
        }
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}