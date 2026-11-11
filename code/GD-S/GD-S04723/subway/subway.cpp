#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int C, n, m, D, Q;
ll a[X];
struct edge {
  int l;
  ll w;
};
vector<edge> to[X];
ll dis[505][505];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> C >> n >> m >> D >> Q;
  cfor (i, 1, m) cin >> a[i];
  cfor (i, 1, n) {
    int len;
    cin >> len;
    cfor (j, 1, len) {
      int u; ll w;
      cin >> u >> w;
      to[u].push_back({i, w});
    }
  }
  cfor (i, 1, n) cfor (j, 1, n) if (i != j) dis[i][j] = inf;

  cfor (u, 1, m) {
    for (edge e1: to[u]) {
      for (edge e2: to[u]) {
        dis[e1.l][e2.l] = min(dis[e1.l][e2.l], e1.w + e2.w);
      }
    }
  }

  cfor (k, 1, n)
    cfor (i, 1, n)
      cfor (j, 1, n)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

  while (Q--) {
    int x, y;
    cin >> x >> y;
    ll ans = inf;
    for (edge e1: to[x]) {
      for (edge e2: to[y]) {
        ans = min(ans, dis[e1.l][e2.l] + e1.w + e2.w);
      }
    }
    ans += a[x] + a[y];
    cout << ans << "\n";
  }

  return 0;
}