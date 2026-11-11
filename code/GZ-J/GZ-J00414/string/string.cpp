// GZ_J00414 张苇然 实验三中 
#include <bits/stdc++.h>
#define ll long long
#define vll vector <ll>
#define pll pair <ll,char>
using namespace std;
const int N = 2e6;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	vector <pll> a (n + 1);
	ll cnt = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i].first >> a[i].second;
		cnt += a[i].first; 
	}
	if (cnt <= 2e5) {
		string s = " ";
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= a[i].first;j++) s += a[i].second; 
		}
		int m;
		if (cnt % 2) {
			m = cnt / 2 + 2;
			ll ans = 0;
			for (int i = m;i <= cnt;i++) {
				if (s[i] != s[2 * m - 2 - i]) ans++;
			}
			cout << ans;
		}
		else {
			m = cnt / 2 + 1;
			ll ans = 0;
			for (int i = m;i <= cnt;i++) {
				if (s[i] != s[2 * m - i - 1]) ans++;
			}
			cout << ans;
		}
	}
	else {
		cout << 0;
	}
	return 0;
}
