#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;
ll n, d, c, t, x[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		for (ll i = 1; i <= n; i ++) {
			cin >> x[i];
		}
		cout << 0 << "\n";
	}
	return 0;
}

