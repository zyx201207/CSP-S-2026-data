#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], ans, maxa;
string st;
char c[200005];
//bool check(string s) {
//	int len = s.size();
//	for(int i = 0;i < (s.size() + 1) / 2;i++) {
//		if(s[i] != s[len - i - 1]) {
//			return 0;
//		}
//	}
//	return 1;
//}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
		maxa = max(a[i], maxa);
	}
	if(n <= 200000 && maxa <=400) {
		string s;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= a[i];j++) {
				s += c[i];
			}
		}
		int len = s.size();
		for(int i = 0;i <= len / 2;i++) {
			if(s[i] != s[len - i - 1]) {
				ans++;
			}
		}
		cout << ans;
	} else {
		int l = 1, r = n;
		while(l < r) {
			if(c[l] != c[r]) {
				if(a[l] <= a[r]) {
					ans += a[l];
					a[r] -= a[l];
					l++;
				} else {
					ans += a[r];
					a[l] -= a[r];
					r--;
				}
			} else {
				l++, r--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
