#include<bits/stdc++.h>
const int N = 5e2+5, M = 5e5+5;
using namespace std;
#define ll long long
namespace Pinball{
    int n, m, d, q, a[M];
    vector<pair<int, int>> G[M];
    ll dis[N][N];
    void Purgatory(){
        cin >> n >> m >> d >> q;
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1;i <= n;i++) dis[i][i] = 0;
        for (int i = 1;i <= m;i++) cin >> a[i];
        for (int i = 1;i <= n;i++){
            int k;
            cin >> k;
            while (k--){
                int p, w;
                cin >> p >> w;
                G[p].emplace_back(i, w);
            }
        }
        for (int i = 1;i <= m;i++){
            for (auto [u, w1] : G[i]){
                for (auto [v, w2] : G[i]){
                    if (u != v){
                        dis[u][v] = min(dis[u][v], (ll)w1 + w2);
                    }
                }
            }
        }
        for (int k = 1;k <= n;k++){
            for (int i = 1;i <= n;i++){
                for (int j = 1;j <= n;j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        while (q--){
            int u, v;
            cin >> u >> v;
            ll ans = 1e18;
            for (auto [x, w1] : G[u]){
                for (auto [y, w2] : G[v]){
                    ans = min(ans, w1 + w2 + dis[x][y]);
                }
            }
            ans += a[u] + a[v];
            cout << ans << '\n';
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1, c;
    cin >> c;
	while (T--) Pinball::Purgatory();
	return 0;
}