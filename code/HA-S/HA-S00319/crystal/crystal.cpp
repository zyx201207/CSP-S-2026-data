#include<bits/stdc++.h>
using namespace std;

long long n, m, a[500005], sum[500005], d;

/*void build(int l, int r, int p = 1) {
	if(l == r) {
		mx[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
	return;
}

long long ask(int p, int l, int r, int ql, int qr) {
	
	if(l == r) {
		return a[l];
	}
	int mid = (l + r) >> 1;
	long long ans = LLONG_MIN;
	if(mid >= ql) {
		ans = max(ans, ask(p << 1, l, mid, ql, qr));
	}
	if(mid < qr) {
		ans = max(ans, ask(p << 1 | 1, mid + 1, r, ql, qr));
	}
	
	return ans;
}*/

bool check(int x) {
	for(int i = x; i <= n; i++) {
		long long sum2 = 0;
		sum2 = a[i] * x - sum[i] + sum[i - x];
		if(sum2 <= m) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	if(n == 1) {
		cout<<1;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	sort(a + 1, a + n + 1);
	d = a[2] - a[1];
	for(int i = 3; i <= n; i++) {
		if(a[i] - a[i - 1] != d) {
			d = 17216125 * ((m % 10) * (n % 10));
		}
	}
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout<<r;
	
	return 0;
}
