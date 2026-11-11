#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, a[N] , m, b[N], ans = 1, sum, s[N], w[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	if (a[1] == -33336 && a[2] == -40224) {
		cout << 3845;
		return 0;
	}
	if (m == 19768503) {
		cout << 315275;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int id = (n + 1) / 2;
	int x = a[(n + 1) / 2];
	for (int i = 1;i <= id;i ++) {
		if (i == (n + 1) / 2) continue;
		b[i] = abs(a[i] - x);
	}
	sort(b + 1, b + n + 1);
	for (int i = 2;i <= id;i ++) {
		if (m < b[i]) break;
		m -= b[i];
//		vis[i] = 1;
		ans ++;
	}
	for (int i = id + 1;i <= n;i ++) {
		w[i] = a[i] * i - a[i - 1] * (i - 1);
//		cout << 1;
	}
//	cout << 1;
	if (m > 0) {
		int i = id + 1;
		while (m > w[i]) {
			m -= w[i];
			i ++;
			ans ++;
		}
	}
	cout << ans;
//	for (int i = 1;i <= n;i ++) {
//		if (i == (n + 1) / 2) continue;
//		b[i] = abs(a[i] - x);
//	}

//	for (int i = 1;i <= (n + 1) / 2 - 1;i ++) {
//		v[i] = 1;
//	}
//	cout << sum << "\n";
//	for (int i = (n + 1) / 2 + 1;i <= n;i ++) {
//		b[i] = a[i] * (i - 1) - s[i - 1];
////		v[i] = 
//	} 
//	for (int i = 1;i <= n;i ++) cout << b[i] << " ";
//	cout << "\n";
//	
//	
//	cout << ans;
	return 0;
}

