#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6 + 5;
int c, t;
ll n, d;
ll x[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (ll i = 1; i <= n; i++){
			cin >> x[i];
		}
		if (d == 1){
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		for (ll i = 1; i <= n - 2; i++){
			for (ll j = i + d + 1; j <= n; j++){
				if ((x[j] - x[i]) % d == 0){
					continue;
				}
				else{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}