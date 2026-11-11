#include <fstream>
#include <vector>
#include <iostream>

int main() {
	std::ifstream in("string.in");
	std::ofstream out("string.out");
	
	int n;
	in >> n;
	// int len = 0;
	std::vector<std::pair<char, long long>> v;
	v.reserve(n);
	for (int i = 1; i <= n; ++i) {
		long long a; char c;
		in >> a >> c;
		// merge blocks
		if ((v.end() - 1)->first == c) {
			(v.end() - 1)->second += a;
		} else { v.push_back({c, a}); }
		// len += a;
	}
	int p = 0, q = v.end() - v.begin() - 1;
	long long ans = 0;
	while (p < q) {
		auto n = std::min(v[p].second, v[q].second);
		// std::clog << n << " " << v[p].second << " " << v[q].second << std::endl;
		if (v[p].first != v[q].first) {
			ans += static_cast<long long>(n);
		}
		v[p].second -= n;
		v[q].second -= n;
		if (v[p].second == 0) {
			p++;
		}
		if (v[q].second == 0) {
			q--;
		}
	}
	out << ans;
}
