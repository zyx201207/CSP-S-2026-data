#include<bits/stdc++.h>
#define inf 214748364711111111
#define ll long long
using namespace std;
ll c, n, m, d, q, flag=1, T;
ll w[51111];
ll z[51111];
ll g[5111][5111];
ll a[5111][5111];
ll t[5111][5111];
ll ans[5111][5111];
int main (){
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= m; ++i) cin >> w[i];
    for (ll i = 1; i <= m; ++i){
        for (ll j = 1; j <= m; ++j) g[i][j] = inf;
    }
    for (ll i = 1; i <= n; ++i){
        cin >> z[i];
        for (ll j = 1; j <= z[i]; ++j){
            cin >> a[i][j] >> t[i][j];
            if (T && T!=t[i][j]) flag = 0;
            if (!T) T = t[i][j];
        }
        for (ll j = 1; j <= z[i]; ++j){
            for (ll k = 1; k <= z[i]; ++k){
                ll u = a[i][j], v = a[i][k];
                ll ts = t[i][j] + t[i][k];
                if (u == v) continue;
                g[u][v] = min (g[u][v], ts);
            }
        }
    }
    if (m > 1000){
        vector<ll>f[25111];
        for (ll i = 1; i <= m; ++i){
            for (ll j = 1; j <= m; ++j){
                if (g[i][j]!=inf){
                   f[i].push_back(j);
                }
            }
        }
        ll vis[25111];
        for (ll i = 1, x, y; i <= q; ++i){
            cin >> x >> y;
            fill (vis, vis+m+1, 0);
            queue<ll>que;
            que.push(x);
            vis[x] = w[x];
            while (!que.empty()){
                ll u = que.front(); que.pop();
                if (u == y) break;
                for (auto v : f[u]){
                    if (!vis[v]){
                        que.push(v);
                        vis[v] = vis[u]+2*T;
                    }
                }
            }
            cout << vis[y]+w[y] << "\n";
        }
        return 0;
    }
    for (ll k = 1; k <= m; ++k){
        for (ll i = 1; i <= m; ++i){
            for (ll j = 1; j <= m; ++j){
                g[i][j] = min (g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
    for (ll i = 1, x, y; i <= q; ++i){
        cin >> x >> y;
        cout << g[x][y]+w[x]+w[y] << "\n";
    }

    return 0;
}
