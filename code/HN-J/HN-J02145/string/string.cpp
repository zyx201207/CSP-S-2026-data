#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int, char> mp[200000];
int cnt = 0;

signed main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  int n;
  for (int i = 0; i != t; ++ i) {
  	int a;
  	cin >> a;
  	char c;
  	cin >> c;
  	mp[i].first = a, mp[i].second = c;
  	n += a;
	}
	int mid = 0, tmp = 0;
	for (int i = 0; i != t; ++ i) {
		tmp += mp[i].first;
		if ((n >> 1) < tmp) {
			mid = i;
			if (mp[i].first % 2 == 1) {
				-- mp[i - 1].first;
				if (mp[i].second != mp[i - 1].second) ++ cnt;
			}
			break;
		}
	}
	int l = mid - 1, r = mid;
	//cout << l << ' ' << r << endl;
	while (l != -1 && r != t) {
		int& c1 = mp[l].first,& c2 = mp[r].first;
		int k = c1 - c2;
		char& sb1 = mp[l].second,& fcku = mp[r].second;
		if (sb1 != fcku) cnt += min(c1, c2);
		if (k > 0) {
			c1 = k;
			++ r;
		} else if (k < 0) {
			c2 = -k;
			-- l;
		} else {
			-- l;
			++ r;
		}
		//cout << k << ' ' << l << ' ' << r << endl;
	}
	cout << cnt;
  return 0;
}

