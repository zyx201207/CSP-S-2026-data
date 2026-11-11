#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10; 
int n;
ll m, a[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0, la = 1;
	ll now = 0;
	for(int i = 1; i <= n; i++) {
//		cerr << ans << ' ' << la << ' ' << now << '\n';
		now += (ll)(i - la) * (a[i] - a[i - 1]);
		if(now <= m) ans = max(ans, i - la + 1);
		else {
			while(la <= i && now > m) now -= a[i] - a[la], ++la;
			ans = max(ans, i - la + 1);
		}
//		cerr << ans << ' ' << la << ' ' << now << '\n';
	}
	cout << ans << '\n';
	return 0;
}
/*
10 15
-1145 1 2 3 4 5 6 7 8 9
*/
