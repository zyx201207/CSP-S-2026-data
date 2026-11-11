#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

void gb(std::vector<int> bits[32], int wucha[32], std::set<int>& already, int a) {
	bool flag = false;
	if (already.find(a) != already.end()) flag = true;
	already.insert(a);
	for (int i = 0; i < 32; ++i) {
		if (a & (1 << i)) {
			bits[i].push_back(a);
			if (flag) {
				wucha[i] ++;
			}
		}
	}
}

int n, m;

int solve(std::vector<int>& a, int b = 31) {
	// Guess?
	if (b <= 1) {
		std::sort(a.begin(), a.end());
		int ans = a[a.size() - 1];
		for (int i = 2; i <= m; ++i) {
			ans &= a[a.size() - i];
		}
		return ans;
	}
	std::vector<int> bits[32];
       	int wucha[32];
	std::set<int> al;
	for (auto i : a) {
                gb(bits, wucha, al, i);
        }
        for (int i = b; i >= 0; --i) {
		if (static_cast<int>(bits[i].size()) >= m && reinterpret_cast<int>(static_cast<int>(bits[i].size()) + wucha[i]) <= m) {
			int ans = bits[i][0];
			for (std::size_t j = 1; j < bits[i].size(); ++j) {
				ans &= bits[i][j];
			}
			return ans;
		}
                if (static_cast<int>(bits[i].size()) > m) {
			return solve(bits[i], i - 1);
                }
        }
	return 0;
}

int main() {
	std::ifstream in("and.in");
	std::ofstream out("and.out");

	in >> n >> m;
	std::vector<int> a;
	a.reserve(n);
	for (int i = 1; i <= n; ++i) {
		int t;
		in >> t;
		a.push_back(t);
	}
	
	out << solve(a);
}
