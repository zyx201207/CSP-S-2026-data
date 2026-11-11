#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
int c, t, n;
ll d, land[N], step[N], way[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		ll tot = 0;
		for(int i = 1; i <= n; i++) {
			cin >> land[i];
			if(i <= 3) continue;
			ll f1 = land[i] - land[i - 1];
			ll f2 = land[i - 1] - land[i - 3];
			ll f3 = land[i] - land[i - 2];
			ll f4 = land[i - 2] - land[i - 3];
			ll f5 = land[i] - land[i - 3];
			if(f1 <= d && f2 <= d && f3 <= d && f4 <= d && f5 > d) 
				tot++;
		}
		cout << tot << '\n';
	}
	return 0;
}