#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
int testid, T, n;
ll d, x[N];
namespace taskA {
  void main() {
    ll t = d / (x[2] - x[1]);
    if (t <= 1) { cout << "0\n"; return; }
    t = 2 * t - 1;
    cout << (n > t ? n - t : 0) << "\n";
  }
}
namespace taskB {
  void main() {
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
      int p = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
      if (i - p < 2) continue;
      int q = lower_bound(x + 1, x + n + 1, x[p + 1] - d) - x;
      if (p + 2 <= i && x[p + 2] - x[q] <= d) continue;
      ans += p - q;
    }
    cout << ans << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin >> testid >> T;
  while (T --) {
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) cin >> x[i];
    if (11 <= testid && testid <= 12) taskA::main();
    else if (13 <= testid && testid <= 14) taskB::main();
  }
  return 0;
}