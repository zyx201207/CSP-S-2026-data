#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 505;
const ll INF = 1e18;
int c, n, m, d, Q, len[M];
ll vis[N];
ll w[N], dis[M][M];
vector<ll>a[M], t[M];
vector<pair<int, ll> >g[N];
int main(){
    // freopen("subway.in", "r", stdin);
    // freopen("subway.out", "w", stdout);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> len[i];
        int k = len[i];
        t[i].resize(k + 5), a[i].resize(k + 5);
        for(int j = 1;j <= k;j++){
            cin >> a[i][j] >> t[i][j];
            g[a[i][j]].push_back({i, t[i][j]});
        }
    }
    for(int i = 1;i <= m;i++)vis[i] = INF;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= len[i];j++)vis[a[i][j]] = t[i][j];
        for(int j = i + 1;j <= n;j++){
            ll mn = INF;
            for(int k = 1;k <= len[j];k++)mn = min(mn, vis[a[j][k]] + t[j][k]);
            dis[i][j] = dis[j][i] = mn;
        }
        dis[i][i] = 0;
        for(int j = 1;j <= len[i];j++)vis[a[i][j]] = INF;
    }
    for(int k = 1;k <= n;k++)for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for(int i = 1;i <= Q;i++){
        int x, y;ll ans = INF;
        cin >> x >> y;
        for(auto j : g[x])for(auto k : g[y])ans = min(ans, dis[j.first][k.first] + j.second + k.second);
        cout << w[x] + w[y] + ans << "\n";
    }
    return 0;
}