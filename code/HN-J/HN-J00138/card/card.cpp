#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5, M = 3e5 + 5;

int n, m, a[N];

namespace subtask1 {
  bool check() {
    return n <= 500;
  }

  int cnt[N];

  void solve() {
    for (int i = 1; i <= n; i++) {
      vector<int> v;
      for (int j = i; j <= n; j++) {
        bool f = 0;
        for (int k : v) {
          if (k == a[j]) f = 1;
        }
        while (f && v.back() != a[j]) {
          v.pop_back();
        }
        if (!f) {
          v.push_back(a[j]);
        }
      }
      for (int j : v) {
        cnt[j]++;
      }
    }
    for (int i = 1; i <= m; i++) {
      cout << cnt[i] << " ";
    }
  }
} // 24pts

int main() {
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  subtask1::solve();
  return 0;
}
