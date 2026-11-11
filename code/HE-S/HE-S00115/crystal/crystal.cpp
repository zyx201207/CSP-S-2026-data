#include <bits/stdc++.h>
using namespace std;
// Oct31==Dec25?
// CCF is best 
constexpr int maxn = 5e5 + 10;

long long a[maxn], ans = INT_MIN;

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }
  
  sort(a + 1, a + n + 1);
  
  for (int i = 1; i <= n; i ++) {
    long long tm = m, cnt = 1;
    for (int j = i; j >= 1; j --) {
      if (j == i) continue;
      if (tm >= a[i] - a[j] && a[j] <= a[i]) {
	    tm -= a[i] - a[j];
      	cnt ++;
      }
    }

    ans = max(ans, cnt);
  }
  cout << ans;
  return 0;
}
