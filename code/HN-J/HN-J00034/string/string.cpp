#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
const int maxn = 2e5 + 5;


int n;
ll ans = 0;
ll a[maxn];
char b[maxn];
ll cnt = 0;
ll c[maxn];
char d[maxn];
ll tot = 0;
string s;
bool flag = 0; 
void solve() {
	
	int l = 1, r = cnt;
	ll let = 1, rig = tot;
	while (let <= rig) {
		ll lf = c[l] - let + 1;
		ll lr = rig - c[r - 1];
//		cout << l << " " << let << " " << lf << "\n";
//		cout << r << " " << rig << " " << lr << "\n";
//		cout << "\n";
		if (d[l] == d[r]) {
			if (lf <= lr) {
				let = c[l] + 1;
				rig -= lf;
				++l;
				if (lf == lr) --r;
			}
			else {
				rig = c[r-1];
				let += lr;
				--r;
			}
		}
		else {
			if (lf <= lr) {
				let = c[l] + 1;
				rig -= lf;
				++l;
				if (lf == lr) --r;
				ans += lf;
			}
			else {
				rig = c[r-1];
				let += lr;
				--r;
				ans += lr;
			}
		}	
	}

	cout << ans << "\n";	
}
//void solve2() {
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= a[i]; ++j) {
//			s += b[i];
//		}
//	}
//	int l = 0, r = s.length() - 1;
//	while (l <= r) {
//		if (s[l] != s[r]) ++ans;
//		--l, ++r;
//	}
//	cout << ans << "\n";
//}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	AC;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		if (i > 1 && b[i] != b[i-1]) flag = 1;
	}
	if (!flag) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (b[i] != b[i-1]) {
			c[++cnt] = a[i];
			d[cnt] = b[i];
		}
		else c[cnt] += a[i];
	}
	for (int i = 1; i <= cnt; ++i) {
		c[i] += c[i - 1];
		tot = c[i];
	}
	
//	cout << tot;
//	cout << "\n";
//	for (int i = 1; i <= cnt; ++i) {
//		cout << c[i] << " ";
//	}
//	cout << "\n";
	
	solve();
	
	return 0;
}
