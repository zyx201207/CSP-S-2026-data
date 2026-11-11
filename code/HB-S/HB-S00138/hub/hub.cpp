#include <bits/stdc++.h>
using namespace std;
int testid, T, n, m;
namespace taskA {
  int updiv(int a, int b) { return (a + b - 1) / b; }
  void main() {
    if (m == n) cout << "0\n";
    else if (m >= n / 2) cout << "1\n";
    else cout << updiv(n / 2 - m, 2) + 1 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin >> testid >> T;
  while (T --) {
    cin >> n >> m;
    for (int i = 1; i < n; i ++) {
      int u, v; cin >> u >> v;
    }
    if (13 <= testid && testid <= 14) taskA::main();
  }
  return 0;
}