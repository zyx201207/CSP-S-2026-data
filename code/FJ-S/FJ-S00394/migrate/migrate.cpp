#include <bits/stdc++.h>

namespace ZeroOf149 {

using std::cin;
using std::cout;

using ll = long long;

constexpr int N = 2e6 + 5, Inf = 0x3f3f3f3f;

struct Data {
  void update(const Data& o) {
    if (val < o.val) return;
    if (val > o.val) {
      *this = o;
      return;
    }
    cnt = std::min(cnt + o.cnt, 3ll);
  }
  
  ll val, cnt;
};

int c, TT, n;
ll d, a[N], Ans;
Data dp[N], fw[N];

void edit(int x, const Data& v) {
  for (; x; x &= x - 1) fw[x].update(v);
}

Data query(int x) {
  Data ret = {Inf, 0};
  for (; x <= n; x += x & -x) ret.update(fw[x]);
  return ret;
}

int my_main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  
  for (cin >> c >> TT; TT--;) {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Ans = 0;
    for (int l = 1; l < n; ++l) {
      dp[l] = {0, 1};
      std::fill(fw + 1, fw + n + 1, Data{Inf, 0});
      edit(l, dp[l]);
      for (int r = l + 1, j = l; r <= n; ++r) {
        while (j < r && a[r] - a[j] > d) ++j;
        dp[r] = query(j);
        if (dp[r].val >= Inf) break;
        ++dp[r].val;
        edit(r, dp[r]);
        if (dp[r].cnt == 2) ++Ans;
      }
    }
    cout << Ans << '\n';
  }
  
  return 0;
}

}

int main() { return ZeroOf149::my_main(); }

