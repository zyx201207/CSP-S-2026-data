#include <bits/stdc++.h>
using namespace std;

long long a[200000];
int c[30];	// 统计每个位出现的次数 

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		
		int k = 0;
		while ((1 << k) <= a[i]) {
			if (a[i] & (1 << k)) c[k]++;
			k++;
		}
	}
	sort(a, a+n, greater<long long>());
	
	long long ans = (1 << 31) - 1;
	for (int k = 29, i = 0, choosed = 0; choosed < m && k >= 0 && i < n;)
	if (c[k] >= m) {
		while (!(a[i] & (1 << k))) i++;
		ans &= a[i];
		choosed++;
		i++;
	} else k--;
	
	cout << ans;
	return 0;
}
