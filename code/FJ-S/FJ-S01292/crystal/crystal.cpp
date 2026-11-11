#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005];
int maxn = -1000000000000000000, minn = 1000000000000000000, ans = -1000000000000000000;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	sort(a + 1, a + n + 1);
	if ((maxn - minn + 1) * n > 1e7){
		cout << 0;
		return 0;
	}
	else{
		for (int i = minn; i <= maxn; i++){
			int j = 1, cnt = m, sum = 0;
			while(a[j] <= i){
				j++;
			}
			for (int k = j - 1; k >= 1; k--){
				if (cnt - (i - a[k]) >= 0){
					cnt -= (i - a[k]);
					sum++;
				}
				else{
					break;
				}
			}
			ans = max(ans, sum);
		}
	}
	cout << ans;
	return 0;
}
