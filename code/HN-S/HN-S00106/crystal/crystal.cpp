#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 7;
int n, m, a[N], ans;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1, j = 1, sum = 0; i <= n; i++){
		while(sum > m) sum -= a[i] - a[j], ++j;
		ans = max(ans, i - j + 1);
		if(i < n) sum += (i - j + 1) * (a[i + 1] - a[i]);
	}
	cout << ans << '\n';
	return 0;
} 
