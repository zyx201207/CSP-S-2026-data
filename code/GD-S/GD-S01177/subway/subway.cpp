#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T> void chkmax(T &x, T y) {if (x < y) x = y;}
template<typename T> void chkmin(T &x, T y) {if (x > y) x = y;}
#define UP(x,y,z) for (int x = y; x <= z; ++x)

namespace imc {
    constexpr int N = 505, M = 500005;
    constexpr ll INF = (ll)1e17;
    vector<pil> G[M];
    int w[M];
    ll dis[N][N];
    int n, m, d, q;
    void main() {
        cin >> n >> m >> d >> q;
        for (int i = 1; i <= m; ++i) cin >> w[i];
        UP(i,1,n) UP(j,1,n) dis[i][j] = INF;
        UP(i,1,n) dis[i][i] = 0;
        for (int i = 1; i <= n; ++i) {
            int c; cin >> c;
            for (int j = 0; j < c; ++j) {
                int x, y; cin >> x >> y;
                G[x].emplace_back(i, y);
            }
        }
        UP(i,1,m) {
            for (auto x : G[i]) for (auto y : G[i]) {
                chkmin(dis[x.first][y.first], x.second + y.second);
                chkmin(dis[y.first][x.first], x.second + y.second);
            }
        }
        UP(i,1,n) UP(j,1,n) UP(k,1,n) {
            chkmin(dis[j][k], dis[j][i] + dis[i][k]);
        }
        UP(i,1,q) {
            int x, y; cin >> x >> y;
            ll ans = INF;
            for (auto i : G[x]) for (auto j : G[y])
                chkmin(ans, dis[i.first][j.first] + i.second + j.second);
            cout << ans + w[x] + w[y] << '\n';
        }
    }
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1,c;
    cin >> c;
    // cin >> T;
    while (T--) {
        imc::main();
    }
}