// 14.42 14.55
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 510;
const int M = 5e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;

inline void gmin(ll &a, ll b) { a = min(a, b); }

int n, m, d, q;
ll a[M];
vector<pii> b[M];

ll dis[N][N];

int main() {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int x, y; cin >> x >> y;
            b[x].push_back({i, y});
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) dis[i][j] = INF;
        dis[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(pii j : b[i]) for(pii k : b[i]) {
            gmin(dis[j.first][k.first], j.second + k.second);
            gmin(dis[k.first][j.first], j.second + k.second);
        }
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                gmin(dis[i][j], dis[i][k] + dis[k][j]);
    
    while(q--) {
        int x, y; cin >> x >> y;
        ll ans = INF;
        for(pii j : b[x]) for(pii k : b[y]) {
            ans = min(ans, dis[j.first][k.first] + j.second + k.second);
        }
        cout << ans + a[x] + a[y] << '\n';
    }

    return 0;
}