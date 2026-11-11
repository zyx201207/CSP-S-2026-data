#include<bits/stdc++.h>
using namespace std;
long long n, m, t, ans_id, ans, cnt, a[500005], stp[500005];
void check(long long x) {
	cnt = 0;
	t = m;
	for (long long i = x; i >= 1; i--){
		if (t >= abs(a[x] - a[i])) {
			t = t - abs(a[x] - a[i]);
			cnt++;
		} else {
			break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	sort(a + 1, a + 1 + n);
	a[n + 1] = -1e18;
	for (long long i = n; i >= 1; i--) {
		if (a[i] == a[i + 1]) {
			stp[i] = stp[i + 1];
		} else {
			stp[i] = i;
		}
	}
	if (n <= 5000) {
		for (long long i = 1; i <= n; i++) {
			check(i);
			ans = max(ans, cnt);
			if (ans >= cnt) {
				ans_id = cnt;
			}
		}
	} else {
		long long l = 1, r = n;
		while(l <= r) {
			long long mid = (l + r) / 2;
			cout << l << " " << r << " " << mid << endl;
		//	cout << mid << " " ;
			check(stp[mid]);
			cout << ans << " " << cnt << endl;
			if (cnt < ans) {
				r = mid - 1;
			} else {
				ans = cnt;
				ans_id = mid;
				l = mid + 1;
				
			} 
		}
	}
	cout << ans;
	return 0;
}
