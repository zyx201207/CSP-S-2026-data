#include <fstream>
#include <vector>
#include <algorithm>

int main() {
	std::ifstream in("crystal.in");
	std::ofstream out("crystal.out");

	long long n, m;
	in >> n >> m;
	std::vector<int> a;
	a.reserve(n);
	for (int i = 1; i <= n; ++i) {
		int t;
		in >> t;
		a.push_back(t);
	}
	std::sort(a.begin(), a.end());	
	long long now = 0, i = 0;
	for (; i < n; ++i) {
		if (i == 0) continue;
		now += static_cast<long long>(i) * static_cast<long long>(a[i] - a[i - 1]);
		if (now > m) {
			break;
		}
	}
	int ans = i;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i + 1]) {
			int r = i++;
			while (a[r] == a[i++]) {}
			ans = std::max(ans, i - r);
		}
	}
	out << ans << std::endl;
}
