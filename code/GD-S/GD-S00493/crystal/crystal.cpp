#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], ans, sum[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)cin >> a[i];
	if (n == 1){
		cout << "1";
		return 0;
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1;i <= n;i++)sum[i] = sum[i - 1] + a[i];
//	for (int i = 1;i <= n;i++)cout << a[i] << " ";
//	cout << "\n";
	for (int i = 1;i <= n;i++){
		int l = 1, r = i, cans = -1;
		while (l <= r){
			int mid = (l + r) >> 1;
			if ((a[i] * (i - mid + 1)) - (sum[i] - sum[mid - 1]) <= m){
				cans = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
//		cout << "#" << cans << "\n";
		if (cans ^ (-1))ans = max(ans, (i - cans + 1));
	}
	cout << ans;
	return 0;
} 
