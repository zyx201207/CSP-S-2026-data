#include <bits/stdc++.h>

using namespace std;

#define int long long

using i64 = long long;
using pii = pair<int, int>;

#define fi first 
#define se second
#define mkp make_pair

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 20; 
const int M = 510; 
int c, n, m, d, q; 
vector<int> a[M], t[M];
vector<pii> bel[N];
int w[N];
int dis[M][M]; 
int val[N];
int s;
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1, k; i <= n; ++i){
        cin >> k;
        for(int j = 0, a_, t_; j < k; ++j){
            cin >> a_ >> t_;
            a[i].push_back(a_), t[i].push_back(t_); 
            bel[a_].push_back(mkp(i, t_));
        }
    }
    memset(dis, 0x3f, sizeof(dis)); 
    for(int i = 1; i <= n; ++i){
        dis[i][i] = 0; 
        for(int j = 1; j <= m; ++j) val[j] = 0;  
        for(int j = 0; j < (int)a[i].size(); ++j){
            val[a[i][j]] = t[i][j]; 
        }   
        for(int j = i + 1; j <= n; ++j){
            for(int k = 0; k < (int)a[j].size(); ++k){
                if(val[a[j][k]]){
                    dis[i][j] = min(dis[i][j], val[a[j][k]] + t[j][k]);
                    dis[j][i] = min(dis[j][i], val[a[j][k]] + t[j][k]);
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                if(i != j && j != k && i != k){
                    dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]);
                }
            }
        }
    }
    for(int r = 1; r <= q; ++r){
        int x, y; cin >> x >> y; 
        int ans = INF;
        for(int i = 0; i < (int)bel[x].size(); ++i){
            for(int j = 0; j < (int)bel[y].size(); ++j){
                int bx = bel[x][i].fi, by = bel[y][j].fi;
                int tx = bel[x][i].se, ty = bel[y][j].se;
                ans = min(ans, dis[bx][by] + w[x] + w[y] + tx + ty);                 
            }
        }
        cout << ans << '\n';
    }

    return 0; 
}

// attention : not nongcuo n and m 
// attention : memory
// 4:00 I wanna goto WC!!!