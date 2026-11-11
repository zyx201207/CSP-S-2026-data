#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define eb emplace_back
using namespace std;
using ll = long long;
using db = double;
using vi = vector<int>;
using p2 = pair<int, int>;

const int N = 5e5 + 10, M = 510, K = 22;
const ll inf = 2e18;

int c, n, m, W[N], q, d;

ll dis[M][M]; 
vector<p2 > sta[N];

ll ans;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> c >> n >> m >> d >> q;

    //!!!! n is line, m is station
    For (i, 1, m) cin >> W[i];
    For (i, 1, n) {
        int ki; cin >> ki;
        For (j, 1, ki) {
            int v, w; cin >> v >> w;
            sta[v].push_back({i, w}); // sta;
        }
    }

    For (i, 1, n) For (j, 1, n) dis[i][j] = inf;
    For (i, 1, n) dis[i][i] = 0;

    // For (i, 1, m) {
    //     For (j, 0, sta[i].size() - 1)
    //         cout << sta[i][j].first << ',' << sta[i][j].second << ' ';
    //     cout << '\n';
    // }

    For (i, 1, m) {
        For (u, 0, (int)sta[i].size() - 1){
            For (v, 0, (int)sta[i].size() - 1) {
                // cout << "???";
                if (u == v) continue;
                int u0 = sta[i][u].first, u1 = sta[i][v].first;
                int w0 = sta[i][u].second, w1 = sta[i][v].second;
                // cout << "DEDE" << u0 << ' ' << u1 << ' ' << w0 << ' ' << w1 << '\n';
                dis[u0][u1] = dis[u1][u0] = min(dis[u0][u1], 1ll * w0 + w1);
            }
        }
    }

    For (k, 1, n)
        For (i, 1, n)
            For (j, 1, n) 
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    // cout << "DEbug" << '\n';

    // For (i, 1, n) {
    //     cout << i << ':';
    //     For (j, 1, n) cout << j << ' ' << dis[i][j] << ',';
    //     cout << '\n';
    // }

    For (i, 1, q) {
        int s, t; cin >> s >> t;
        ans = inf;
        For (u, 0, (int)sta[s].size() - 1){
            For (v, 0, (int)sta[t].size() - 1) {
                int u0 = sta[s][u].first, u1 = sta[t][v].first;
                int w0 = sta[s][u].second, w1 = sta[t][v].second;
                ans = min(ans, dis[u0][u1] + w0 + w1);
                // cout <<"!!!???!!?" << dis[u0][u1] << ' ' << w0 << ' ' << w1 << '\n';
            }
        }
        cout << ans + W[s] + W[t] << '\n';
    }
    
    return 0;
}