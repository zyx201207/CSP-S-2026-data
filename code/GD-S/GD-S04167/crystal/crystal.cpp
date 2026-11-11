#include <algorithm>
#include <iostream>

int n, m;
long long ans;
long long energy[500005];
long long pre[500005];



int main() {
	std::freopen("crystal.in", "r", stdin);
	std::freopen("crystal.out", "w", stdout);
	
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> energy[i];
	}
	
	std::sort(energy + 1, energy + 1 + n);
	
	int l = 1, r = 1;
	
	long long tmp = 0;
	
	while (r <= n) {
//		std::cout << "Debug: circle start " << l << " " << r << std::endl;
		if (tmp <= m) {
			ans = std::max(ans, (long long)(r - l + 1));
			r++;
			tmp += (energy[r] - energy[r - 1]) * (r - l);
		} else {
			tmp -= energy[r] - energy[l];
			l++;
		}
//		std::cout << "Debug: circle end " << l << " " << r << " " << tmp << std::endl;
	}

	std::cout << ans;
}
