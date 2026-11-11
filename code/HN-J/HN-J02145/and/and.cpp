#include <bits/stdc++.h>
using namespace std;

int tarr[200000];
bitset<30> arr[200000];

signed main() {
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> s;
  int ans = pow(2, 30) - 1;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i != a; ++ i) {
  	int t;
  	cin >> t;
  	arr[i] = tarr[i] = t;
	}
	int cnt = 0, f = 0;
	for (int i = 29; i >= 0; -- i) {
		for (int j = 0; j != a; ++ j) {
			if (arr[j][i] && !f) {
				++ cnt;
				s.push_back(j);
			} else if (f && !arr[j][i] && find(s.begin(), s.end(), j) != s.end()) {
				-- cnt;
				swap(s[j], s[s.size() - 1]);
				s.pop_back();
			}
		}
		if (cnt > b) {
			f = 1;
		} else if (cnt == b) {
			break;
		} else {
			cnt = 0;
		}
	}
	for (int i = 0; i != s.size(); ++ i) {
		ans &= tarr[s[i]];
	}
	cout << ans;
  return 0;
}
