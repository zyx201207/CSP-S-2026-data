#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 2e5 + 10;
ll c, T, n, k, ans;
ll a[MAX];

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		ans = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i){
			int p1 = upper_bound(a + 1, a + n + 1, a[i] + k) - a;
			int p2 = p1 - 2;
			ll p3 = upper_bound(a + 1, a + n + 1, a[p2] + k) - a;
			ans += min(n + 1, p3) - p1;
		}
		cout << ans << '\n';
	}
	return 0;
}
