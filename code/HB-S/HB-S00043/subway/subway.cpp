#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll N = 510, M = 5e5, D = 30, INF = 0x3f3f3f3f3f3f3f3f;
struct walk {
    ll train, tim;
    walk(ll tr = 0, ll ti = 0) :
        train(tr), tim(ti) {}
};
// n : subw num, m : subw station, 
// a[i][j] : subw i pass dot j, j \in [1, k[i]]
ll c, n, m, d, q, x, y, ans;
vector<ll> a[N], t[N];
ll w[N], k[N], dis[N][N];
walk station[N][D];
ll station_num[N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        a[i].resize(k[i] + 10);
        t[i].resize(k[i] + 10); 
        for(int j = 1; j <= k[i]; j++) {
            cin >> a[i][j];
            cin >> t[i][j];
            station[a[i][j]][++station_num[a[i][j]]] = walk(i, t[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j) dis[i][j] = INF;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= station_num[i]; j++)
            for(int k = 1; k <= station_num[i]; k++)
                dis[station[i][j].train][station[i][k].train] = min(
                dis[station[i][j].train][station[i][k].train],
                station[i][j].tim + station[i][k].tim);
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
    while(q--) {
        cin >> x >> y;
        ans = INF;
        for(int i = 1; i <= station_num[x]; i++) {
            for(int j = 1; j <= station_num[y]; j++) {
                ans = min(ans, w[x] + w[y] + station[x][i].tim
                + station[y][j].tim + dis[station[x][i].train][station[y][j].train]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}