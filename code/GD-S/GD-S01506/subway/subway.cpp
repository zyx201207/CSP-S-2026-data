#include <bits/stdc++.h>
#define F(i, l, r) for (int i = (l); i <= (r); i ++)
#define G(i, r, l) for (int i = (r); i >= (l); i --)
#define MP make_pair
#define fi first
#define se second
#define pb push_back
using namespace std; 
typedef long long LL;

const int N = 507, M = 5e5 + 7; 

template <typename T>
void Fmax(T &x, T y) { x = x > y ? x : y; }
template <typename T>
void Fmin(T &x, T y) { x = x < y ? x : y; }

LL read() {
  char c = getchar();
  LL x = 0, p = 0;
  while (c < '0' || c > '9')
    p ^= (c == '-'), c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return p ? -x : x;
}

LL w[M], dis[N][N];
int c, n, m, d, q;
vector<pair<int, int>> buc[M];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  c = read(), n = read(), m = read(), d = read(), q = read();
  F(i, 1, m) w[i] = read();
  for (int i = 1, k; i <= n; i ++) {
    k = read();
    for (int j = 1, a, t; j <= k; j ++) {
      a = read(), t = read();
      buc[a].pb(MP(i, t));
    }
  }
  memset(dis, 0x3f, sizeof dis);
  F(i, 1, n) dis[i][i] = 0;
  F(i, 1, m) for (auto x : buc[i]) for (auto y : buc[i])
    Fmin(dis[x.fi][y.fi], (LL) x.se + y.se);
  F(k, 1, n) F(i, 1, n) F(j, 1, n) Fmin(dis[i][j], dis[i][k] + dis[k][j]); 
  for (int i = 1, x, y; i <= q; i ++) {
    x = read(), y = read();
    LL res = 1e18;
    for (auto j : buc[x]) for (auto k : buc[y])
      Fmin(res, dis[j.fi][k.fi] + j.se + k.se);
    cout << res + w[x] + w[y] << '\n';
  }
  return 0;
}

