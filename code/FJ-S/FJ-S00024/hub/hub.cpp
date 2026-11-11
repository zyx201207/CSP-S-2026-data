#include <bits/stdc++.h>

int c, t, n, k;

void solve() {
	std::cin >> n >> k;
	for(int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
	}
	if(k == n) std::cout << "0\n";
	else if(k >= n / 2) std::cout << "1\n";
	else {
		std::cout << ((n/2-1) - (k-2)) / 4 + 1 << '\n';
	}
	return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	std::cin >> c >> t;
	while(t--) solve();

	return 0;
}
