#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 505, MAXM = 5e5 + 5;
ll dis[MAXN][MAXN];
vector<pair<int, int>> vec[MAXM];
int w[MAXM];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int a, t;
            cin >> a >> t;
            vec[a].push_back({i, t});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++){
        int len = vec[i].size();
        for (int idx1 = 0; idx1 < len; idx1++){
            int uid = vec[i][idx1].first, ut = vec[i][idx1].second;
            for (int idx2 = 0; idx2 < len; idx2++){
                int vid = vec[i][idx2].first, vt = vec[i][idx2].second;
                dis[uid][vid] = min(dis[uid][vid], (ll)ut + vt);
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--){
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        int lenx = vec[x].size(), leny = vec[y].size();
        for (int idx1 = 0; idx1 < lenx; idx1++){
            int uid = vec[x][idx1].first, ut = vec[x][idx1].second;
            for (int idx2 = 0; idx2 < leny; idx2++){
                int vid = vec[y][idx2].first, vt = vec[y][idx2].second;
                ans = min(ans, dis[uid][vid] + ut + vt);
            }
        }
        ans += w[x] + w[y];
        cout << ans << '\n';
    }
    return 0;
}