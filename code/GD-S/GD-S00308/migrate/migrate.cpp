#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3 + 5;
int dp[N][N], a[N], n, d, c, t;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		int ch = a[2] - a[1];
		int cnt = d / ch;
		if(cnt != 2) cout << "0\n";
		else{
			int ans = max(0ll, n - 3);
			cout << ans << endl;
		}
	}
	return 0;
}
