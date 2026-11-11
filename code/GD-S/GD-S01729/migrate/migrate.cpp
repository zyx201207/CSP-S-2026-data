#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long c, t, n, d;
vector<long long> a(N);
void solve(){
	cin >> n >> d;
	for (long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	if ((n * 1.0 / 2 - n / 2) >= 0.5)cout << n / 2 << '\n';
	else cout << n / 2 - 1 << '\n';
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--){
		solve();
	}
	return 0;
}

