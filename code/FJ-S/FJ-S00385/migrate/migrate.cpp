#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll c, t, n, d, ans;
ll x[2000005], dis[5005], cnt[5005];

void bfs(int s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  queue<pii> q;
  q.emplace(s, 0);
  dis[s] = 0;
  cnt[s] = 1;
  while (q.size()) {
    int u = q.front().first;
    int step = q.front().second;
    q.pop();
    step++;
    for (int v = u + 1; v <= n && x[v] - x[u] <= d; v++) {
      if (step < dis[v]) {
        cnt[v] = 1;
        dis[v] = step;
      } else if (step == dis[v])
        cnt[v]++;
      else
        continue;
      q.emplace(v, step);
    }
  }
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  cin >> c >> t;
  while (t--) {
    ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
      cin >> x[i];
    for (int i = 1; i <= n; i++) {
      bfs(i);
      for (int j = i + 1; j <= n; j++)
        if (cnt[j] == 2)
          ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}


