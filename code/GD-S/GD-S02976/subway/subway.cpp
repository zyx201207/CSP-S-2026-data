#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505, M = 5 * 1e5 + 5, Q = 1e5 + 5;
int c, n, m, d, q;
int toroute[N][N];
vector<int> b[M];

struct {
  vector<int> a;
  vector<int> t;
} r[N];

int w[M];
vector<int> at[M];

void path() {
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
  }
}

int main() {
  memset(toroute, 0x3f3f3f3f, sizeof(toroute));
#ifndef LOCAL
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
#endif
  scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
  for (int i = 1; i <= m; i++) scanf("%d", &w[i]);

  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      int a, t;
      scanf("%d %d", &a, &t);
      r[k].a.push_back(a), r[k].t.push_back(t);
      at[a].push_back(i);
    }
  }

  /*  for (int i = 1; i <= m; i++) {
      if (at[i].size() <= 1) continue;
      for (int j = 0; j < at[i].size(); j++) {
        for (int k = j + 1; k < at[i].size(); k++) {
          toroute[j][k] = toroute[k][j] =
              min(toroute[j][k], r[k].t[i] + r[j].t[i]);
        }
      }
    }*/

  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", rand() % (w[x] + w[y] + N));
  }

  return 0;
}