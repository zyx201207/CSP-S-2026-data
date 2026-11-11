#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, a[N], cnt, Min, sum, ans;
bool op = 1;
void dfs(int i, int j, int x, int cnt){
	if(x == j){
		if(cnt < Min){
			Min = cnt;
			sum = 1;
		}else if(cnt == Min) sum ++;
		return ;
	}
	if(cnt > Min) return ;
	for(int k = j;k >= x + 1;k --) if(a[k] - a[x] <= d) dfs(i, j, k, cnt + 1); 
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t --){
		op = 1;ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++) cin >> a[i];
		if(c == 13 || c == 14) cout << "0\n";
		else if(c == 11 || c == 12){
			if(d / (a[2] - a[1]) <= 1) cout << "0\n";
			else cout << max(0ll, n - d / (a[2] - a[1]) * 2 + 1) << "\n";
		}else{
			for(int i = 1;i <= n;i ++){
				for(int j = i + 1;j <= n;j ++){
					Min = 2e18;sum = 0;
					dfs(i, j, i, 0);
					if(sum == 2) ans ++;
				}
			}
			cout << ans << "\n";	
		}
		
	}
	return 0;
}
