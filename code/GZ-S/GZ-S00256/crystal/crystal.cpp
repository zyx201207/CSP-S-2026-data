// GZ-S00256 ³ÂêÅÖñ 
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5+10;
int n, m;
int sum, cnt = 1;
int a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	sum = m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i]; 
	}
	sort(a+1, a+1+n);
	int d = a[2] - a[1], di = d;
	for(int i = n-1; i >= 1; i--) {
		if(di <= m) {
			m -= di;
			a[i] += di;
			di += d;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
