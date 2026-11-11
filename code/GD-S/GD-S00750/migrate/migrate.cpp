#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000010;
int c, t, n, d, ans, x[N], nxt[N], dis[N], cnt[N];
vector<int> g[N];
queue<int> q;
signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  scanf("%lld%lld", &c, &t);
  while(t--) {
    scanf("%lld%lld", &n, &d);
    for(int i = 1; i <= n; i++)
      scanf("%lld", &x[i]);
    for(int i = 1; i <= n; i++) {
      int l = i, r = n, best = i;
      while(l <= r) {
        int mid = (l + r) / 2;
        if(x[mid] <= x[i] + d) {
          best = mid;
          l = mid + 1;
        } else
          r = mid - 1;
      }
      nxt[i] = best;
      g[i].clear();
      g[i].push_back(nxt[i]);
      if(nxt[i] > i + 1)
        g[i].push_back(nxt[i] - 1);
      if(nxt[i] > i + 2)
        g[i].push_back(nxt[i] - 2);
    }
    ans = 0;
    for(int i = n; i >= 1; i--) {
      for(int j = i; j <= n; j++)
        dis[j] = 1e18, cnt[j] = 0;
      dis[i] = 0;
      cnt[i] = 1;
      q.push(i);
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: g[u]) {
          if(dis[u] + 1 < dis[v]) {
            dis[v] = dis[u] + 1;
            cnt[v] = cnt[u];
            q.push(v);
          } else if(dis[v] == dis[u] + 1) 
            cnt[v] = min(cnt[v] + cnt[u], 3ll);
        }
      }
      for(int j = i; j <= n; j++)
        ans += cnt[j] == 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}

