#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

   freopen("hub.in", "r", stdin);
   freopen("hub.out", "w", stdout);

  int c, t;
  cin >> c >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n == k) {
    	cout << 0 << endl;
	} else {
		int m = (n - 1) / 2;
		if (k >= m) {
			cout << 1 << endl;
		} else {
			cout << 1 + (m - k + 3) / 4 << endl;
		}
	}
  }

  return 0;
}
