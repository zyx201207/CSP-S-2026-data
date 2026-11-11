#include <bits/stdc++.h>
#define loop(i, a, b) for(int i = (a); i <= (b); i++)
#define rloop(i, a, b) for(int i = (a); i >= (b); i--)
#define lowbit(x) ((x) & (-(x)))
typedef long long ll;
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
const ll INF = 1e18;
int c, n, m, d, q;
struct node {
    int id;
    ll t, st;
};
vector<node> bel[M]; 
ll w[M], dis[N][N];
void solve() {
    cin >> c >> n >> m >> d >> q;
    loop(i, 1, m) cin >> w[i];
    loop(i, 1, n) {
        int k; cin >> k;
        loop(j, 1, k) {
            node u; cin >> u.id >> u.t;
            bel[u.id].push_back({i, u.t});
        }
    }
    loop(i, 1, n) loop(j, 1, n) dis[i][j] = INF;
    loop(i, 1, n) dis[i][i] = 0;

    loop(i, 1, m) {
        for(auto x : bel[i]) for(auto y : bel[i]) {
            dis[x.id][y.id] = min(x.t + y.t, dis[x.id][y.id]);
        }
    }
    loop(k, 1, n) loop(i, 1, n) loop(j, 1, n) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    loop(i, 1, q) {
        int a, b; cin >> a >> b;
        ll ans = INF;
        for(auto x : bel[a]) for(auto y : bel[b]) {
            ans = min(ans, dis[x.id][y.id] + x.t + y.t);
        }
        cout << ans + w[a] + w[b] << "\n";
    }
}
//Oct31==Dec25?

signed main() {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin >> t; while(t--)
    solve();
    return 0;
    
}
//g++ crystal.cpp -o a -O2 -static -std=c++14
//./a

