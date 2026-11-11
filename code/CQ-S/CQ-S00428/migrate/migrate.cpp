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
const int N = 2e6 + 5, M = 21, p = 1e9 + 7, inf = 8e18;
namespace xyx{
    int n, D, a[N];
    namespace Force{
        int vis[N], d[N], f[N]; vi g[N];
        using PII = std::pair<int, int>;
        std::priority_queue<PII, std::vector<PII>, std::greater<PII> > pq;
        il void dij(int s){
            L(i, s, n) d[i] = inf / 2, vis[i] = f[i] = 0; d[s] = 0, f[s] = 1, pq.push({0, s});
            while(!pq.empty()){
                int u = pq.top().second, dis = pq.top().first; pq.pop();
                if (vis[u] || dis != d[u]) continue; vis[u] = 1;
                rep(v, g[u]){
                    if (v < s) continue;
                    if (d[v] > d[u] + 1){
                        d[v] = d[u] + 1, pq.push({d[v], v});
                        f[v] = f[u];
                    }
                    else if (d[v] == d[u] + 1) f[v] += f[u];
                }
            }
        }
        il void slv(){
            int ans = 0; L(i, 1, n) g[i].clear();
            L(i, 1, n){
                int j = i;
                while(j < n && a[j + 1] - a[i] <= D) j++, g[i].pb(j), g[j].pb(i);
            }
            L(i, 1, n){
                dij(i);
                L(j, i + 1, n) if (f[j] == 2) ans++;
            }
            std::cout << ans << "\n";
        }
    } // namespace Force
    il void slv(){ int sid, t = 1; std::cin >> sid >> t; while(t--){
        std::cin >> n >> D; L(i, 1, n) std::cin >> a[i];
        if (n == 1){ std::cout << "0\n"; continue; }
        if (n <= 5000) Force::slv();
        else{
            int F = 1; L(i, 2, n) F &= (a[i] - a[i - 1] == a[2] - a[1]);
            if (F){
                int x = a[2] - a[1]; D /= x;
                if (D <= 1) std::cout << "0\n";
                else std::cout << std::max(0LL, n - (2 * D - 1)) << "\n";
                continue;
            }
            Force::slv();
        }
    }
    }
} signed main(){
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    return xyx::slv(), 0;
}
/*
g++ migrate.cpp -o migrate.exe -std=c++14 -O2 -Wall -Wextra -Wshadow "-Wl,--stack=512000000";if($?){./migrate}
*/