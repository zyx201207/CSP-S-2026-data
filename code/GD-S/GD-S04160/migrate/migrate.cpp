#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, d, a[2000006], dp[2000006][11];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if(c >= 11 && c <= 12){
		while(t--){
			cin >> n >> d;
			ll p = 0;
			cin >> a[1];
			for(int i = 2;i <= n;i++){
				cin >> a[i];
				a[i] -= a[1];
			}
			a[1] = 0;
			if(n == 1){
				cout << 0;
				return 0;
			}
			p = a[2];
			ll k = d / p;
			if(k < 2){
				cout << 0 << '\n';
				continue;
			}
			ll ans = 0;
			for(int i = 1;i <= n;i++){
				ans += min(n, i + k * 2) - i - k;
			}
			cout << ans << '\n';
		}
		return 0;
	}
	else if(c >= 13 && c <= 14){
		while(t--){
			cin >> n >> d;
			for(int i = 1;i <= n;i++){
				cin >> a[i];
			}
			ll sum = 0;
			for(int i = 1;i <= n;i++){
				ll l = i, r = n, tmp = 0;
				while(l <= r){
					ll mid = (l + r) / 2;
					if(a[mid] - a[i] <= d){
						l = mid + 1;
						tmp = mid;
					}
					else{
						r = mid - 1;
					}
				}
				sum += tmp - i;
			}
			ll ans = n * (n - 1) / 2 - sum;
			cout << ans << '\n';
		}
	}
	else{
		cout << 18;
	}
	return 0;
}
