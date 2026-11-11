#include <bits/stdc++.h>
using namespace std;
long long n, m, cnt[500010], a[500010];
bool cmp(long long a, long long b) {
	return a < b;
}
bool check(int k) {
	for(int i = k; i <= n;i ++) {
		if(cnt[i] - cnt[i - k] + m >= a[i] * k) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1;i <= n;i ++) {
		cnt[i] = cnt[i - 1] + a[i];
	}
	int l = 1, r = n, mid = (l + r) / 2;
	while(r - l >= 5) {
		
		if(check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
		mid = (l + r) / 2;
	}
	for(int i = r; i >= l; i --) {
		if(check(i)) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
