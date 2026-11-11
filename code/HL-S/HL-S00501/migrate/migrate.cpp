#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int a[N];
int dp[N];
int dt[N];

inline int read(){
	int ret = 0;
	bool f = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {ret = ret * 10 + ch - '0'; ch = getchar();}
	return (f ? -ret : ret);
}

signed main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c = read(), T = read();
//	cin >> c >> T;
	while(T--){
		int n = read(), d = read();
//		cin >> n >> d;
		for (int i = 1; i <= n; i++) a[i] = read();
//		cout << 1;
		
		if (c == 11 || c == 12){
			int cent = a[2] - a[1];
			if (d < 2 * cent) cout << 0 << endl;
			else cout << max(1ll * 0, n - (d / cent) * 2 + 1) << endl;
			continue;
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++) dp[j] = 0;
			for (int j = 1; j <= n; j++) dt[i] = 0;
			dp[i] = 1;
			dt[i] = 0;
			for (int j = i + 1; j <= n; j++){
				int find = j - 1;
				if (a[j] - a[j - 1] > d) break;
				
				while(find >= i && a[j] - a[find] <= d){
//					if (!dt[j] || dt[find] + 1 < dt[j]){
					if (dt[find] + 1 != dt[j]){
						dt[j] = dt[find] + 1;
						dp[j] = 0;
					}
					dp[j] += dp[find];
					find--;
				}
				
//				int l = 1, r = j - 1;
//				int mid = (l + r) / 2;
//				while(l < r){
//					if (a[j] - a[mid] > d) l = mid + 1;
//					else r = mid;
//					mid = (l + r) / 2;
//				}
//				for (int k = mid; dt[k] == dt[mid]; k++){
//					dp[j] += dp[k];
//					if (dp[j] > 2) break;
//				}
				
				
				if (dp[j] == 2){
//					cout << i << " " << j << endl;
					ans++;
				}
			}
//			for (int j = i; j <= n; j++) cout << j << " " << dp[j] << " " << dt[j] << endl;
		} 
		
		cout << ans << endl;
	}
	return 0;
}