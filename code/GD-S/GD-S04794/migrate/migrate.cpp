#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 2e6 + 3;

int c, t, n;
long long l, x[maxn];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> t;
	while(t--) {
		cin >> n >> l;
		for(int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if(n == 1) {
			cout << 0 << '\n';
			continue;
		}
		long long cha = x[2] - x[1];
		if(cha > l) {
			cout << 0 << '\n';
			continue;
		}
		int step = cha / l;
		long long ans = 0;
		for(int i = step + 1; 
			i <= 2 * step - 1 && i <= n; i++) {
			ans += n - i + 1;
		}
		cout << ans << '\n';
	}
}