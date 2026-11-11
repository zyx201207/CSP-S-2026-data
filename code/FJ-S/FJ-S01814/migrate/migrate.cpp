#include <bits/stdc++.h>
#define eb emplace_back
#define sz(x) int((x).size())

using LL = long long;
using namespace std;

const int N = 2e6 + 10;
LL x[N];
int R[N], cnt[N];
int n;
LL d, ans;

LL F(int n) {
  R[n] = n;
  for (int i = n - 1; i >= 1; i--) {
    R[i] = R[i + 1];
    while (x[R[i]] > x[i] + d) {
      R[i]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    if (R[i] == R[i - 1]) {
      cnt[i]++;
    }
    if (i > 1 && R[i] == R[i - 2]) {
      cnt[i]++;
    }
  }
  LL ans = 0;
  for (int i = n; i >= 1; i--) {
    if (R[i] == i) continue;
    ans += cnt[R[i]] == 1;
    cnt[i] += cnt[R[i]];
  }
  return ans;
}

void solve() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  ans = 0;
  for (int r = 1; r <= n; r++) {
    ans += F(r);
  }
  cout << ans << '\n';
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  cin >> c >> T;
  while (T--) {
    solve();
  }
  return 0;
}