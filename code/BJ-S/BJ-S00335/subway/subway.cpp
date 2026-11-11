#include<bits/stdc++.h>
#define fo(i, l, r) for(int i = (l); i <= (r); ++i)
using namespace std;
const int N = 505, M = 500005;
const long long INF = 1000000000000000000ll;
int c, n, m, d, q, w[M], k[N];
long long f[N][N];
struct Node{
    int a, t;
}; vector<Node> v[N], down[M];
signed main(){
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q; fo(i, 1, m) cin >> w[i];
    fo(i, 1, n){
        cin >> k[i];
        fo(j, 1, k[i]){
            int a, t; cin >> a >> t;
            v[i].push_back({a, t});
            down[a].push_back({i, t});
        }
    }
    fo(i, 1, n) fo(j, 1, n) f[i][j] = INF;
    fo(i, 1, n){
        fo(_i, 0, v[i].size() - 1){
            int a = v[i][_i].a, ti = v[i][_i].t;
            fo(_j, 0, down[a].size() - 1){
                int j = down[a][_j].a, tj = down[a][_j].t;
                if(j == i) continue;
                f[i][j] = f[j][i] = min(f[i][j], (long long)ti + tj);
            }
        }
    }
    fo(i, 1, n) f[i][i] = 0;
    fo(k, 1, n){
        fo(i, 1, n){
            fo(j, 1, n){
                if(f[i][j] > f[i][k] + f[k][j]){
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }
    while(q--){
        int x, y; cin >> x >> y;
        long long ans = INF;
        fo(i, 0, down[x].size() - 1){
            int dx = down[x][i].a, tx = down[x][i].t;
            fo(j, 0, down[y].size() - 1){
                int dy = down[y][j].a, ty = down[y][j].t;
                long long sumt = (long long)tx + ty;
                ans = min(ans, f[dx][dy] + sumt);
            }
        }
        cout << ans + ((long long)w[x] + w[y]) << '\n';
    }
    return 0;
}
// g++ subway.cpp -o subway -O2 -std=c++14 -static