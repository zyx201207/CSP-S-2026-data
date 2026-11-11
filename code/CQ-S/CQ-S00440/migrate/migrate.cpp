#include<bits/stdc++.h>
#define lb(x) (x&-x)
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)

namespace qazabcdef1111 {
using namespace std;
using i64 = long long;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
void chmin(int &x, int c) { x = min(x, c); }
void chmax(int &x, int c) { x = max(x, c); }

const int maxn = 2e6 + 10, mod = 998244353;
int N;
ll D, X[maxn];
int to[21][maxn], S2[21][maxn], S3[21][maxn], sum0[maxn], sum1[maxn];
bool st2[maxn], st3[maxn], st[maxn]; vector<int> adj[maxn]; ll res;
ll tmp[maxn];
int Mx[maxn];
void dfs(int u) {
  st[u] = 1;
//  cerr << "u & tmp: " << u << ' ' << tmp[u] << '\n';
  for (auto v : adj[u]) if (!st[v]) {
//    cerr << u << "->" << v << '\n';
    dfs(v);
    sum0[u] += sum0[v];
    sum1[u] += sum1[v];
    chmax(Mx[u], Mx[v]);
  }
  if (!to[0][u] || st3[u]) return;
//  cerr << "u, 0, 1: " << u << ' ' << sum0[u] << ' ' << sum1[u] << '\n';
//  int t = 0;
  { // = 0
    int L = max(u + 1, u < 2 ? 0 : to[0][u - 2] + 1);
    int R = min({N, to[0][u] == 0 ? N : to[0][u], to[0][u - 1] == 0 ? N : to[0][u - 1]});
    ll cur = 1ll * sum0[u] * max(0, R - L + 1);
    res += cur;
//    t = sum0[u];
  }
  { // = 1
    int L = max({u + 1, to[0][u - 1] + 1, Mx[u]});
    int R = min(N, to[0][u] == 0 ? N : to[0][u]);
    res += 1ll * sum1[u] * max(0, R - L + 1);
    chmax(Mx[u], R);
  }
//  sum0[u] = 0;
//  sum1[u] += t;
}

void solve() {
  cin >> N >> D, res = 0;
  L (i, 1, N) cin >> X[i];
  L (i, 0, N + 1) st[i] = st2[i] = st3[i] = 0, sum0[i] = sum1[i] = 0, tmp[i] = 0, Mx[i] = 0;
  L (i, 0, N + 1) adj[i].clear(), to[0][i] = S2[0][i] = S3[0][i] = 0;
  for (int i = N, j = N; i >= 1; i--) {
    while (X[j] - X[i] > D) j--;
    assert(j >= i), to[0][i] = j;
  }
  L (i, 2, N) if (to[0][i] != i) {
    if (to[0][i - 1] == to[0][i]) {
      if (i >= 3 && to[0][i - 2] == to[0][i]) st3[i] = 1;
      else st2[i] = 1;
    }
  }
  to[0][0] = 0;
  L (i, 1, N) if (to[0][i] == i) to[0][i] = 0;
  L (i, 1, N) adj[to[0][i]].push_back(i), S2[0][i] = st2[to[0][i]], S3[0][i] = st3[to[0][i]];
  int K = __lg(N + 1);
  L (j, 1, K) L (i, 0, N) {
    to[j][i] = to[j - 1][to[j - 1][i]];
    S2[j][i] = S2[j - 1][i] + S2[j - 1][to[j - 1][i]];
    S3[j][i] = S3[j - 1][i] + S3[j - 1][to[j - 1][i]];
  }
  L (i, 1, N) if (to[0][i] != i) {
    int s = 0, n = i, Lp = 0, Lu = i, Rp = 0, Ru = i;
    R (j, K, 0) if (!S3[j][n]) n = to[j][n], s += (1 << j);
    R (j, K, 0) if (!S2[j][Lu]) Lu = to[j][Lu], Lp += (1 << j);
    Lu = to[0][Lu];
    Rp = Lp, Ru = Lu;
    R (j, K, 0) if (!S2[j][Ru]) Ru = to[j][Ru], Rp += (1 << j);
    if (s <= Lp) Lu = n;
    if (s <= Rp) Ru = n;
    sum0[to[0][i]]++;
    sum0[to[0][Lu]]--;
    sum1[to[0][Lu]]++;
    sum1[to[0][Ru]]--;
  }
  dfs(0);
  cout << res << '\n';
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T = 1; cin >> T >> T;
  while (T--) solve();
  return 0;
}
} signed main() {
  freopen ("migrate.in", "r", stdin), freopen ("migrate.out", "w", stdout);
  return qazabcdef1111::main();
}
/*
0 2
6 4
-3 0 1 2 3 4
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

real:
3
6

0 1
10 21
0 7 14 21 28 35 42 49 56 63

real:
5

0 3
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

real:
7
5
5

*/
/*
oth < migrate1.in > migrate.out
fc migrate.out migrate1.ans
oth < migrate2.in > migrate.out
fc migrate.out migrate2.ans
oth < migrate3.in > migrate.out
fc migrate.out migrate3.ans
oth < migrate4.in > migrate.out
fc migrate.out migrate4.ans
oth < migrate5.in > migrate.out
fc migrate.out migrate5.ans
oth < migrate6.in > migrate.out
fc migrate.out migrate6.ans

*/
/*
migrate < migrate1.in > migrate.out
fc migrate.out migrate1.ans
migrate < migrate2.in > migrate.out
fc migrate.out migrate2.ans
migrate < migrate3.in > migrate.out
fc migrate.out migrate3.ans
migrate < migrate4.in > migrate.out
fc migrate.out migrate4.ans
migrate < migrate5.in > migrate.out
fc migrate.out migrate5.ans
migrate < migrate6.in > migrate.out
fc migrate.out migrate6.ans

*/
