#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505, M = 5e5 + 5;
const ll INF = 1e18;
vector<pair<ll, ll> > station[M];
int c, n, m, d, q;
ll w[M], dp[N][N];
inline void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k, a, t;
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> a >> t;
            station[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dp[i][j] = INF;
        dp[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < station[i].size(); j++){
            for(int k = j + 1; k < station[i].size(); k++){
                auto u = station[i][j], v = station[i][k];
                dp[u.first][v.first] = dp[v.first][u.first] = min(dp[u.first][v.first], u.second + v.second);
            }
        }
    }
    floyd();
    while(q--){
        ll ans = INF;
        int x, y;
        cin >> x >> y;
        for(auto u : station[x]){
            for(auto v : station[y]){
                ans = min(ans, dp[u.first][v.first] + u.second + v.second + w[x] + w[y]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}