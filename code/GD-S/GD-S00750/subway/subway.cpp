#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 510, M = 500010, D = 21, INF = 1e18;
int c, n, m, d, q, w[M], k, a, t, x, y, ans, cnt[M], e[M][D][2], dis[N][N];
signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
  for(int i = 1; i <= m; i++)
    scanf("%lld", &w[i]);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &k);
    for(int j = 1; j <= k; j++) {
      scanf("%lld%lld", &a, &t);
      cnt[a]++;
      e[a][cnt[a]][0] = i;
      e[a][cnt[a]][1] = t;
    }
  }
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(i != j)
        dis[i][j] = INF;
  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= cnt[i]; j++)
      for(int k = 1; k <= cnt[i]; k++)
        if(e[i][j][1] + e[i][k][1] < dis[e[i][j][0]][e[i][k][0]])
          dis[e[i][j][0]][e[i][k][0]] = e[i][j][1] + e[i][k][1];
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  while(q--) {
    scanf("%lld%lld", &x, &y);
    ans = INF;
    for(int i = 1; i <= cnt[x]; i++)
      for(int j = 1; j <= cnt[y]; j++)
        ans = min(ans, e[x][i][1] + dis[e[x][i][0]][e[y][j][0]] + e[y][j][1]);
    ans = ans + w[x] + w[y];
    printf("%lld\n", ans);
  }
  return 0;
}

