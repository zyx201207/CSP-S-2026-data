#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5 * 1e5 + 5;
int n;
ll m, a[N];

struct e {
  int u, v;
  ll w;
};
vector<e> E;
vector<int> elist[N];
int ans;

int dfs(int x, int w, int c) {
  for (int i : elist[x]) {
    if (E[i].w * c + w > m) break;
    dfs(E[i].v, w + E[i].w * c, c + 1);
  }

  if (ans >= c) return 0;
  ans = c;
  return 1;
}

int main() {
#ifndef LOCAL
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
#endif
  scanf("%d %lld", &n, &m);

  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

  sort(a + 1, a + 1 + n);

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (a[j] - a[i] <= m) {
        E.push_back({i, j, a[j] - a[i]});
        elist[i].push_back(E.size() - 1);
      } else
        break;
    }

  for (int i = 1; i <= n / 2; i++)
    if (!dfs(1, 0, 1)) break;

  printf("%d", ans);
  return 0;
}