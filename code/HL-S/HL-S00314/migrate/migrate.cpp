#include <bits/stdc++.h>
using namespace std;
int c, t, ans, n, d, a[2000005];
//æ‡¿Î == e-s-1 
void dfs(int last, int len, int res, int &s){
	if(res == len){
		s++;
		return ;
	}
	for(int i=last+1; i<=n; i++){
		if(a[i]-a[last] <= d && a[last]-a[i] <= d){
			//cout << last << ' ' << i  << ' ' << len << ' ' << res << ' ' << s << endl;
			dfs(i, len, res+1, s); 
		}
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		n = 0;
		d = 0;
		ans = 0;
		for(int i=0; i<=2000005; i++) a[i] = 0;
		cin >> n >> d;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		} 
		if(a[2]-a[1] > d){
			cout << 0;
			continue;
		}
		for(int i=2; i<=n-1; i++){
			for(int j=1; j<=n; j++){
				int sum = 0;
				dfs(j, i, 1, sum);
				//cout << sum << endl;
				if(sum == 2){
					ans++;
				}
				sum = 0;
			}
		}
		cout << ans-1 << endl;
	} 
	return 0;
}
