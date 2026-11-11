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
int N, M, A[maxn], sum[maxn], res;

void solve() {
  cin >> N >> M;
  L (i, 1, N) cin >> A[i];
  sort (A + 1, A + 1 + N);
  L (i, 1, N) sum[i] = sum[i - 1] + A[i];
  L (i, 1, N) {
    int l = 1, r = i;
    while (l < r) {
      int mid = (l + r) >> 1;
      ((i - mid + 1) * A[i] - (sum[i] - sum[mid - 1]) <= M ? r = mid : l = mid + 1);
    }
    chmax(res, i - l + 1);
  }
  cout << res << '\n';
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T = 1;
  while (T--) solve();
  return 0;
}
} signed main() {
  freopen ("crystal.in", "r", stdin), freopen ("crystal.out", "w", stdout);
  return qazabcdef1111::main();
}
/*
crystal < crystal1.in > crystal.out
fc crystal.out crystal1.ans
crystal < crystal2.in > crystal.out
fc crystal.out crystal2.ans
crystal < crystal3.in > crystal.out
fc crystal.out crystal3.ans
crystal < crystal4.in > crystal.out
fc crystal.out crystal4.ans

*/
