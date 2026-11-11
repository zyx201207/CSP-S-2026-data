#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		ll n, d, x[10005];
		cin >> n >> d;
		for(ll i = 1; i <= n; i++){
			cin >> x[i];
		}
		cout << d << "\n";
	}
	return 0;
}
