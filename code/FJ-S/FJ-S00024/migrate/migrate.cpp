#include <bits/stdc++.h>

const int N = 2000003;
int c, t, n;
long long d;
std::vector<long long> X(N, 0);

void solve() {
	std::cin >> n >> d;
	for(int i = 1; i <= n; ++i) {
		std::cin >> X[i];
	}
	if(c == 11 || c == 12) {
		long long e = X[2] - X[1];
		if(d < 2 * e) {
			std::cout << "0\n";
		} 
		else {
			std::cout << std::max(0ll, n - (d/e* 2-1)) << '\n';
		}
	}
	else if(c == 13 || c == 14) {
		long long ans = 0;
		for(int i = 1; i <= n; ++i) {
			int j = std::upper_bound(X.begin()+1, X.begin()+1+n, X[i]+d) - X.begin() - 1;
			if(j-1 <= i) continue;
			int k = std::upper_bound(X.begin()+1, X.begin()+1+n, X[j-1]+d) - X.begin() - 1;
			int l = std::upper_bound(X.begin()+1, X.begin()+1+n, X[j-2]+d) - X.begin();
			ans += std::max(0, k - l + 1);
		}
		std::cout << ans << '\n';
	}
	else std::cout << "0\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::cin >> c >> t;
	while(t--) solve();
	return 0;
}
