#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
const int N = 500005, M = 300005;
int n, m;
ll a[N], dp[N], ans[M];
bool vis[N];
vector <int> G[N], pos[M];
void dfs(int cur) {
    vis[cur] = dp[cur] = 1;
    for (auto v : G[cur]) { if (!vis[v]) dfs(v); dp[cur] += dp[v]; }
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].push_back(i);
    for (int i = 1; i <= n; i++) { if (pos[a[i]].back() < n) G[pos[a[i]].back() + 1].push_back(i); }
    for (int i = 1; i <= n; i++) { if (!vis[i]) dfs(i); }
    for (int i = 1; i <= n; i++) ans[a[i]] += dp[i];
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}