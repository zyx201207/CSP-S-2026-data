#include<bits/stdc++.h>
#define lb(x) (x&-x)
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long

namespace qazabcdef1111 {
using namespace std;
using i64 = long long;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
void chmin(int &x, int c) { x = min(x, c); }
void chmax(int &x, int c) { x = max(x, c); }

const int maxn = 5e5 + 10, mod = 998244353;
vector<pii> q[maxn]; // (w, id)
int N, M, D, Q, w[maxn], g[510][510];

void solve() {
double st = clock();
  cin >> N >> N >> M >> D >> Q;
  L (i, 1, N) L (j, 1, N) g[i][j] = i == j ? 0 : 1e18;
  L (i, 1, M) cin >> w[i];
  L (i, 1, N) {
    int sz; cin >> sz;
    L (j, 1, sz) { int x, w; cin >> x >> w, q[x].push_back({w, i}); }
  }
  L (i, 1, M) {
    int sz = (int)q[i].size();
    L (j, 0, sz - 1) L (k, j + 1, sz - 1) {
      int w = q[i][j].first + q[i][k].first, a = q[i][j].second, b = q[i][k].second;
      chmin(g[a][b], w), chmin(g[b][a], w); 
    }
  }
  L (k, 1, N) L (i, 1, N) L (j, 1, N) chmin(g[i][j], g[i][k] + g[k][j]);
  while (Q--) {
    int x, y, res = 1e18; cin >> x >> y;
    for (auto [w1, i1] : q[x]) for (auto [w2, i2] : q[y]) chmin(res, g[i1][i2] + w1 + w2);
    cout << w[x] + w[y] + res << '\n';
  }
double ed = clock();
  cerr << "time: " << ed - st << " ms\n";
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
} signed main() {
  freopen ("subway.in", "r", stdin), freopen ("subway.out", "w", stdout);
  return qazabcdef1111::main();
}
/*
subway < subway1.in > subway.out
fc subway.out subway1.ans
subway < subway2.in > subway.out
fc subway.out subway2.ans
subway < subway3.in > subway.out
fc subway.out subway3.ans
subway < subway4.in > subway.out
fc subway.out subway4.ans
subway < subway5.in > subway.out
fc subway.out subway5.ans
subway < subway6.in > subway.out
fc subway.out subway6.ans
subway < subway7.in > subway.out
fc subway.out subway7.ans

*/
