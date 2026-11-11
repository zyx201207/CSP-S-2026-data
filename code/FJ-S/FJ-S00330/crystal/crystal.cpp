#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	int eq = 0;
	vector<long long> a(n + 10);
	bool em = 1;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		if(i > 2 && a[i] - a[i - 1] != a[2] - a[1]) {
			em = 0;
		}
	}
	if(em) {
		int l = 1, r = n;
		int mid;
		while(l < r) {
			mid = (l + r) / 2;
			if((a[1] + a[mid]) * mid > 2 * m) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cout << mid;
		return 0;
	}
	sort(a.begin() + 1, a.begin() + n+1);
	if(n * n <= 1e10){
		int maxt = -1;
		for (int i = 1;i <= n;i ++) {
			int tn = 1;
			long long tm = m;
			for (int j = i - 1;j >= 1;j --) {
				if (tm >= abs(a[i] - a[j])) {
					tn ++;
					tm -= abs(a[i] - a[j]);
				} else {
					continue;
				}
			}
			maxt = max(maxt, tn);
		}
		cout << maxt;
		return 0;
	}
	vector<long long> presum(n + 10, 0);
	for(int i = 1;i <= n;i ++) {
		presum[i] = presum[i - 1] + a[i];
	}
	int ans = -1;
	for (int i = 1;i <= n;i ++) {
		int l = 1, r = i;
		while(l < r) {
			if(presum[r] - presum[l - 1] + m < a[r] * (r - l + 1)){
				if(a[l + 1] - a[l] > a[r] - a[r - 1]) {
					l ++;
				} else {
					r --;
				}
			} else {
				break;
			}
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
