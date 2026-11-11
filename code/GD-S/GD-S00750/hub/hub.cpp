#include <bits/stdc++.h>
using namespace std;

const int N = 2000010;
int c, t, n, k, u, v, flag[N], vis[N], cnt, ans, dis[N];
vector<int> g[N];
queue<int> q;
void mark(int u) {
  vis[u] = 1;
  for(int v: g[u])
    if(flag[v] && !vis[v])
      mark(v);
}
int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  scanf("%d%d", &c, &t);
  while(t--) {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
      g[i].clear();
    for(int i = 1; i < n; i++) {
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ans = n;
    for(int i = 0; i < 1 << n; i++) {
      if(__builtin_popcount(i) != k)
        continue;
      for(int j = 0; j < n; j++)
        flag[j + 1] = i >> j & 1;
      for(int j = 1; j <= n; j++)
        vis[j] = 0;
      cnt = 0;
      for(int j = 1; j <= n; j++)
        if(flag[j] && !vis[j]) {
          cnt++;
          if(cnt >= 3)
            break;
          mark(j);
        }
      if(cnt <= 2) {
        for(int j = 1; j <= n; j++) {
          if(flag[j]) {
            q.push(j);
            dis[j] = 0;
          } else
            dis[j] = n * 2;
        }
        while(!q.empty()) {
          int u = q.front();
          q.pop();
          for(int v: g[u])
            if(dis[u] + 1 < dis[v]) {
              dis[v] = dis[u] + 1;
              q.push(v);
            }
        }
        int mx = 0;
        for(int j = 1; j <= n; j++)
          mx = max(mx, dis[j]);
        ans = min(ans, mx);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

