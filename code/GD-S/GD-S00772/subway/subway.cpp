#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define pii pair <int, int>
#define chkmx(a, b) (a = max(a, (b)))
#define chkmn(a, b) (a = min(a, (b)))
using namespace std;
const int N = 505, M = 5e5 + 5;
int n, m, d, q, w[M], mp[N][N];
vector <int> a[N], t[N];
vector <pii> subway[M];
void solve(){
  cin >> n >> n >> m >> d >> q;
  for (int i = 1; i <= m; i ++) cin >> w[i];
  for (int i = 1; i <= n; i ++){
    memset(mp[i], 0x3f, sizeof(int) * (n + 1));
    mp[i][i] = 0;
    int k; cin >> k;
    a[i].resize(k), t[i].resize(k);
    for (int j = 0; j < k; j ++){
      cin >> a[i][j] >> t[i][j];
      subway[a[i][j]].pb(i, t[i][j]);
    }
  }
  for (int i = 1; i <= m; i ++){
    for (uint j = 0; j < subway[i].size(); j ++)
      for (uint k = j + 1; k < subway[i].size(); k ++){
        int u = subway[i][j].first, v = subway[i][k].first, cost = subway[i][j].second + subway[i][k].second;
        chkmn(mp[u][v], cost), chkmn(mp[v][u], cost);
      }
  }
  for (int i = 1; i <= n; i ++){
    for (int j = 1; j <= n; j ++){
      for (int k = 1; k <= n; k ++){
        chkmn(mp[j][k], mp[j][i] + mp[i][k]);
        chkmn(mp[k][j], mp[j][i] + mp[i][k]);
      }
    }
  }
  while (q --){
    int u, v; cin >> u >> v;
    int ans = 4e18;
    for (auto [a, c1] : subway[u]) for (auto [b, c2] : subway[v]) chkmn(ans, mp[a][b] + c1 + c2);
    cout << ans + w[u] + w[v] << '\n';
  }
}
signed main(){
  cin.tie(0)->sync_with_stdio(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  int _ = 1; //cin >> _;
  while (_ --) solve();
  return 0;
}