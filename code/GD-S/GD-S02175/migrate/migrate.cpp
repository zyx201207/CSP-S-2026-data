#include <iostream>
#include <vector>
using namespace std;
#define ll long long
void dfs(int u, int f, int n, int d, vector<ll> x, vector<vector<int>> & dist) {
    if(u > n)
        return;
    dist[u][f] ++;
    for (int i = u + 1; i <= n && x[i] - x[u] <= f; i ++)
        dfs(i, f, n, d, x, dist);
}
void solve() {
    int n, d;
    cin >> n >> d;
    vector<ll> x(n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> x[i];
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i ++)
        dfs(i, i, n, d, x, dist);
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if(i == j)
                continue;
            if(dist[i][j] == 2)
                ans ++;
        }
    }
    cout << ans << endl;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c;
    cin >> c;
    int t;
    cin >> t;
    while(t --)
        solve();
}
/*
ExeCute!
*/