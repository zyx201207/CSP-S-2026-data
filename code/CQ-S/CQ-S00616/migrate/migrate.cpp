#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
typedef long long ll;

int n;
ll d, v[N], a[N], z[N], pr[N];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) v[j] = 1000000000000, pr[j] = 1, z[j] = 0;
		int mv = i, ml = i;
		z[i] = 1;
		pr[i] = 1;
		v[i] = 0;
		v[i + 1] = 1;
		z[i + 1] = 1;
		pr[i + 1] = 2;
		pr[i - 1] = 0;
		if(a[i + 2] - a[i] <= d) {
			pr[i + 2] = 3;
			v[i + 2] = 1;
			z[i + 2] = 1;
		}else pr[i + 2] = 3, v[i + 2] = 2, z[i + 2] = 1;
		for (int j = i + 3; j <= n; j++) {
			ll c = a[j] - d;
			while(ml < n && a[ml] < c) ml++;
			if(a[j] - a[j - 1] > d) break;
			while(mv < n && v[mv] <= v[ml]) {
				mv++;
			}
			if(pr[mv - 1] - pr[ml - 1] == 2) {
				ans++;
			}
			v[j] = v[ml] + 1;
			z[j] = pr[mv - 1] - pr[ml - 1];
			pr[j] = pr[j - 1] + z[j];
//			cout << ml << ' ' << mv << ' ';
		}
//		cout << '\n';
//		for (int j = i; j <= n; j++) cout << v[j] << ' ';
//		cout << '\n';
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("migrate3.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while(T--) {
		solve();
	}
}
/*
6 2 
-4 -3 -2 -1 3 6 
5 3
-2 -1 0 1 2

*/
