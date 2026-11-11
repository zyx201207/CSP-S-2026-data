#include<iostream>
#define int long long
using namespace std;
int c, t, n, d, a[2000005];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c <= 2){
		while(t--){
			cin >> n >> d;
			for(int i = 1; i <= n; i++) cin >> a[i];
			
		}
	}
	if(c >= 11 && c <= 12){
		while(t--){
			cin >> n >> d;
			for(int i = 1; i <= n; i++) cin >> a[i];
			int x = a[2] - a[1], b = d / x, ans = n - b - b + 1;
			if(b <= 1) cout << 0 << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}
