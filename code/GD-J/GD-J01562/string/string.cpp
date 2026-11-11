#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
	int n;
	cin >> n;
	int maxa = -1, tot = 0;
	vector<pair<int, char>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		tot += a[i].first;
		maxa = max(maxa, a[i].first);
	}
	if (maxa <= 500 && n <= 2000) {
		string s = " ";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < a[i].first; ++j) {
				s.push_back(a[i].second);
			}
		}
		int len = s.length(), ans = 0;
		for (int l = 1, r = len - 1; l <= r; ++l, --r) {
			if (s[l] != s[r]) {
				ans++;
			}
		}
		cout << ans << endl;
		return;
	}
	int cnt = 0, ans = 0;
	
	for (int l = 0, r = n - 1; l <= r && cnt <= tot / 2; ) {
		int cl = a[l].first, cr = a[r].first;
		if (a[l].second == a[r].second) {
			if (cl < cr) {
				cnt += cl;
				l++;
				a[r].first -= cl;
			} else if (cl == cr) {
				cnt += cr;
				l++, r--;
			} else {
				cnt += cr;
				r--;
				a[l].first -= cr;
			}
		} else {
			if (cl < cr) {
				cnt += cl;
				if (cnt > tot / 2) {
					ans += cl - tot / 2;
					break;
				}
				l++;
				a[r].first -= cl;
				ans += cl;
			} else if (cl == cr) {
				if (cnt + cl > tot / 2) {
					ans += cl - tot / 2;
					break;
				}
				cnt += cr;
				l++, r--;
				ans += cr;
			} else {
				cnt += cr;
				if (cnt > tot / 2) {
					ans += cr - tot / 2;
					break;
				}
				r--;
				a[l].first -= cr;
				ans += cr;
			}	
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
