#include<bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
#define rg register
#define vi std::vector<int>
#define pb push_back
#define us(n) (1LL << n)
#define L(i, a, b) for (rg int i = (a); i <= (b); i++)
#define R(i, a, b) for (rg int i = (a); i >= (b); i--)
#define rep(i, a) for (rg auto i : (a))
const int N = 5e2 + 5, M = 5e5 + 5, D = 21, p = 1e9 + 7, inf = 8e18;
namespace xyx{
    int sid, n, m, d, q, w[M]; vi pos[M];
    int g[N][N], tim[M][D];
    il void slv(){
        std::cin >> sid >> n >> m >> d >> q; L(i, 1, m) std::cin >> w[i];
        L(i, 1, n){
            int k; std::cin >> k;
            L(j, 1, k){
                int x, t; std::cin >> x >> t; pos[x].pb(i);
                int c = (int)pos[x].size() - 1; tim[x][c] = t;
            }
        }
        L(i, 1, n) L(j, 1, n) g[i][j] = inf / 2; L(i, 1, n) g[i][i] = 0;
        L(x, 1, m){
            L(i, 0, (int)pos[x].size() - 1){
                L(j, i + 1, (int)pos[x].size() - 1){
                    int A = pos[x][i], B = pos[x][j];
                    g[A][B] = g[B][A] = std::min(g[A][B], tim[x][i] + tim[x][j]);
                }
            }
        }
        L(k, 1, n) L(i, 1, n) L(j, 1, n) g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
        L(_, 1, q){
            int x, y; std::cin >> x >> y; int ans = inf / 2;
            L(i, 0, (int)pos[x].size() - 1)
                L(j, 0, (int)pos[y].size() - 1)
                    ans = std::min(ans, g[pos[x][i]][pos[y][j]] + tim[x][i] + tim[y][j]);
            std::cout << ans + w[x] + w[y] << "\n";
        }
        // std::cerr << clock() << "\n";
    }
} signed main(){
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    return xyx::slv(), 0;
}
/*
g++ subway.cpp -o subway.exe -std=c++14 -O2 -Wall -Wextra -Wshadow "-Wl,--stack=512000000";if($?){./subway}
*/