#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int c, t;
int a[500005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		int n, m;
		int ans = 0;
		cin >> n >> m;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		for(int i=1; i<=n; i++) {
			if(a[i+3] - a[i] <= m * 2 && i + 3 <= n && a[i] + m < a[i+3]) ans++;
		}
		cout << ans << endl;
	}
}
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
