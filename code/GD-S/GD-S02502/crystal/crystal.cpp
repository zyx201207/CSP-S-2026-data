#include<bits/stdc++.h>
using namespace std;
int n, ma, sum, total;
long long m, a[500009], d[500009], p[500009];
map<long long, int> tong;
int main (  ) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		tong[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1]; 
		p[i] = p[i - 1] + d[i];
		if(d[i] == d[i - 1]) total++;
		if(a[i] == i) sum++;
	}
	if(m == 0) {
		int cnt = tong.size();
		for(int i = 0; i < cnt; i++) ma = max(ma, tong[i]);
		cout << ma;
		return 0;
	}
	else if(n == 1) {
		cout << 1;
		return 0;
	}
	else if(n == 2) {
		if((m - abs(a[1] - a[2])) % 2 == 0) cout << 2;
		else cout << 1;
		return 0;
	}
	else if(sum == n) {
		int res = 1;
		for(int i = 1; m > 0; i++) {
			m -= i;
			if(m < 0) break;
			res++;
		}
		cout << res + 1;
		return 0;
	}
	else if(total == n - 1) {
		int ans = 1;
		for(int i = d[1]; m > 0; i += d[1]) {
			m -= i;
			if(m < 0) break;
			ans++;
		}
		cout << ans;
		return 0;
	}
	else {
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(m + p[i] >= p[j] && (m - p[j] + p[i]) % (j - i + 1) == 0) ma = max(ma, j - i + 1);
			}
		}
	}
	cout << ma;
	return 0;
} 
