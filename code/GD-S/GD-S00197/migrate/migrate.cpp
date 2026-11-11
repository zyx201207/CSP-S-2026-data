#include<bits/stdc++.h>
using namespace std;

int a[2000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--) {
		int n, d;
		cin >> n >> d;
		for(int i=1; i<=n; i++) cin >> a[i];
		if(a[2] - a[1] > d) cout << 0 << "\n";
		else if(2 * d - 1 < n) {
			cout << 1 << "\n";
		} else cout << 0 << "\n";
	}
	return 0;
}
