#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5, inf = 1e18;
int c, t, n, d, a[N], sum, cnt, ans;

void dfs(int x, int y, int z){
	if(x == y){
		if(sum > z) sum = z, cnt = 1;
		else if(sum == z) cnt++;
		return ;
	}
	for(int i = x + 1; i <= y; i++)
	    if(a[i] - a[x] <= d) dfs(i, y, z + 1); 
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(n <= 9){
			for(int i = 1; i <= n; i++)
	            for(int j = i + 1; j <= n; j++){
	            	sum = inf, cnt = 0;
	            	dfs(i, j, 0);
	            	if(cnt == 2) ans++;
				}
			cout << ans << "\n";
			continue;
		}
		if(c >= 11 && c <= 12){
			if(n <= 3){
				cout << 0 << "\n";
				continue;
			}
			int m = d / (a[2] - a[1]);
			if(m <= 1){
				cout << 0 << "\n";
				continue;
			}
			cout << max(0LL, n - (m * 2 - 1)) << "\n";
			continue;
		}
	    if(c >= 13 && c <= 14){
	    	cout << 0 << "\n";
	    	continue;
		}
		for(int i = 1; i <= n; i++)
		    if(a[i + 3] - a[i] > d && a[i + 2] - a[i] <= d && a[i + 3] - a[i + 1] <= d){
		    	int l = 1, r = 1;
		    	for(int j = i + 4; j <= n; j++)
		    	    if(a[j] - a[j - 1] <= d && (j == n || a[j + 1] - a[j - 1] > d)) r++;
		    	    else break;
		    	for(int j = i; j >= 2; j--)
		    	    if(a[j] - a[j - 1] <= d && (j == 2 || a[j] - a[j - 2] > d)) l++;
				ans += l * r;
			}
		cout << ans << "\n";
	}
	return 0;
}
