#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 50, M = 5e5 + 50;
const ll inf = 2e18;

int ID, n, m, d, q, w[M];
ll dis[N][N];

struct node{
    int u, t;
};
vector<node> x[M];

void Min(ll &x, ll y){ (x > y) && (x = y); }

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> ID >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k, a, t; cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> a >> t;
            x[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = inf;
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int i = 1; i <= m; i++){
        int siz = (int)x[i].size();
        for(int j = 0; j < siz; j++){
            for(int k = j + 1; k < siz; k++){
                int u = x[i][j].u, v = x[i][k].u;
                ll w = 1ll * x[i][j].t + x[i][k].t;
                Min(dis[u][v], w), Min(dis[v][u], w);
            }
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ll tp = dis[i][k] + dis[k][j];
                Min(dis[i][j], tp);
            }
        }
    }
    for(int i = 1; i <= q; i++){
        int s, t; cin >> s >> t;
        ll ans = inf;
        for(int j = 0; j < (int)x[s].size(); j++){
            for(int k = 0; k < (int)x[t].size(); k++){
                node A = x[s][j], B = x[t][k];
                ll tp = dis[A.u][B.u] + A.t + B.t;
                Min(ans, tp);
            }
        }
        ans += 1ll * w[s] + w[t];
        cout << ans << '\n';
    }
    return 0;
}