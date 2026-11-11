#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, ans;
long long a[N];
long long summ[N], cnt, tot[N];
long long sum[N], num[N], m;
bool check(int i, int j) {
	if(num[i] * (tot[i - 1] - tot[j - 1]) - (sum[i - 1] - sum[j - 1]) <= m) return true;
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	a[0] = -1e15;
	for(int i = 1; i <= n; i++){
		if(a[i] != a[i - 1]) {
			cnt++;
			summ[cnt] = 1;
			num[cnt] = a[i];
		} else summ[cnt]++;
	}
	for(int i = 1; i <= cnt; i++) {
		sum[i] = sum[i - 1] + 1ll * summ[i] * num[i];
		tot[i] = tot[i - 1] + summ[i];
	}
	
	for(int i = 1; i <= cnt; i++) {
		ans = max(ans, summ[i]);
		int l = 1, r = i;
		while(l < r) {
			int mid = (l + r) / 2;
			if(check(i, mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		l --;
		if(l != 0) ans = max(ans, tot[i] - tot[l] + (m - num[i] * (tot[i - 1] - tot[l]) + (sum[i - 1] - sum[l])) / (num[i] - num[l]));
		else ans = max(ans, tot[i]);
//		cout << summ[i] << ' ' << num[i] << ' ' << sum[i] << ' ' << tot[i] << ' ' << l << endl;
//		if(l != 0) cout << tot[i] - tot[l] + (m - num[i] * (tot[i - 1] - tot[l]) + (sum[i - 1] - sum[l])) / (num[i] - num[l]) << endl; 
	}
	cout << ans;
	return 0;
} 
