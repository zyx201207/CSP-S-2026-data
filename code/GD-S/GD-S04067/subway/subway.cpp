#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;

const int maxn = 5e5 + 5;
const int maxm = 505;
const ll inf = 1e18;
int c, n, m, d, q, w[maxn];
vector<pii> E[maxn];
ll dis[maxm][maxm];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        while(k--){
            int u, t; cin >> u >> t;
            E[u].pb({i, t});
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        if(i == j) dis[i][i] = 0;
        else dis[i][j] = inf;
    }
    for(int i = 1; i <= m; i++){
        for(auto [u, x] : E[i]) for(auto [v, y] : E[i]){
            dis[u][v] = min(dis[u][v], (ll)x + y);
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= n; k++) dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
    while(q--){
        int x, y; cin >> x >> y;
        ll ans = inf;
        for(auto [u, p] : E[x]) for(auto [v, q] : E[y]){
            ans = min(ans, dis[u][v] + p + q);
        }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }

    return 0;
}