#include <bits/stdc++.h>
using namespace std;
int n;
long long m, cnt, a[500005], ans[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 2; i <= n; i ++) {
		ans[i] = ans[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	//for(int i = 1; i <= n; i ++) cout << ans[i] << " ";
	int l = 1, r = n;
	while(l <= r && ans[r] - ans[l] > m) {
		if(ans[r - 1] - ans[l] < ans[r] - ans[l + 1]) r --;
		else l ++;
	}
	cout << r - l + 1;
	return 0;
}
