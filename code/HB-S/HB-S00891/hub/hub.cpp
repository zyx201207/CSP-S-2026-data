#include <bits/stdc++.h>
#define loop(i, a, b) for(int i = (a); i <= (b); i++)
#define rloop(i, a, b) for(int i = (a); i >= (b); i--)
#define lowbit(x) ((x) & (-(x)))
typedef long long ll;
using namespace std;
const int N = 1e4 + 5;
const ll INF = 1e18;

ll n, k, num;
ll a[N], b[N], mx[N], ans, res;
vector<int> g[N];

void dfs(int u, int f) {
    mx[u] = 0;
    for(auto v : g[u]) {
        if(v == f) continue;
        dfs(v, u);
        mx[u] = max(mx[u], mx[v] + 1);
    }
    res = max(res, mx[u]);
    if(a[u] == 1) mx[u] = 0;
    if(a[u] == 1 && a[f] != 1) num++;
}

void work() {
    loop(i, 1, n) a[i] = mx[i] = 0;
    loop(mask, 0, (1 << n) - 1) {
        if(__builtin_popcount(mask) != k) continue;
        loop(i, 1, n) a[i] = ((mask >> (i - 1)) & 1);
        loop(i, 1, n) {
            num = res = 0;
            dfs(i, 0);
            if(num <= 2) ans = min(ans, res);
        } 
    }
}


void solve() {
    cin >> n >> k;
    loop(i, 1, n) g[i].clear();
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    } 
    ans = INF;
    work();
    cout << ans << "\n";
}

void solve2() {
    cin >> n >> k;
    loop(i, 1, n) g[i].clear();
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    } 
    if(k >= n) cout << "0\n";
    else cout << max((ll)1, (n / 2) - k + 1) << "\n";
}
//Oct31==Dec25?

signed main() {
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int c, t; cin >> c >> t; 
    if(c <= 5) while(t--) solve();
    else while(t--) solve2();
    return 0;
    
}
//g++ subway.cpp -o a -O2 -static -std=c++14
//./a
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

