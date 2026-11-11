#include<bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 5e5 + 5, M = 505;

int n, m, d, q, opt, k, w[N], x, t, y;
vector<pair<int, int>>g[N];
LL ans, f[M][M];

int main(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> opt >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> k;
    for(int j = 1; j <= k; j++){
      cin >> x >> t;
      g[x].push_back({i, t});
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      f[i][j] = (LL)(1e18);
    }
    f[i][i] = 0;
  }
  for(int i = 1; i <= m; i++){
    for(int j1 = 0; j1 < g[i].size(); j1++){
      for(int j2 = 0; j2 < g[i].size(); j2++){
        f[g[i][j1].first][g[i][j2].first] = min(f[g[i][j1].first][g[i][j2].first], 1ll * g[i][j1].second + g[i][j2].second);
      }
    }
  }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  while(q--){
    cin >> x >> y;
    ans = (LL)(1e18);
    for(int j1 = 0; j1 < g[x].size(); j1++){
      for(int j2 = 0; j2 < g[y].size(); j2++){
        ans = min(ans, f[g[x][j1].first][g[y][j2].first] + g[x][j1].second + g[y][j2].second + w[x] + w[y]);
      }
    }
    cout << ans <<'\n';
  }
  return 0;
}
