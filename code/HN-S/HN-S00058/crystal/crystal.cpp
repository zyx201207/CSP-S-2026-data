#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5; 
int n, m;
int ans;
int a[N];
int sum[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m; 
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = 1;
	while(l <= n && r <= n) {
		int val = (r - l + 1) * a[r] - (sum[r] - sum[l - 1]);
		if(val <= m) {
			ans = max(ans, r - l + 1);
			r++;
		}
		else
			l++;
	}
	cout << ans << "\n";
	return 0;
}
