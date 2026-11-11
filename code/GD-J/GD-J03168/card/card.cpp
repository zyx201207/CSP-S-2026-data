#include <cstdint>
#include <iostream>
#include <stack>
#include <vector>

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

class Tree {
private:
	u32 n, V;
	std::vector<std::vector<u32>> e;
	std::vector<u32> val, sz;
	void srh(u32 x) {
		sz[x] = 1;
		for (auto it = e[x].begin(); it != e[x].end(); ++it) {
			srh(*it);
			sz[x] += sz[*it];
		}
	}
public:
	Tree(u32 _n, u32 _m) : n(_n), V(_m), e(n, std::vector<u32>()), val(n, -1u), sz(n, 0) {}
	void setpar(u32 x, u32 p) { e[p].emplace_back(x); }
	void setval(u32 x, u32 v) { val[x] = v; }
	std::vector<u32> getans() {
		srh(0);
		std::vector<u32> ret(V);
		for (u32 i = 0; i < n; ++i) {
			if (val[i] != -1u) {
				ret[val[i]] = sz[i];
			}
		}
		return ret;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	u32 n, m;
	std::vector<u32> a;
	std::cin >> n >> m;
	a.resize(n);
	for (u32 i = n - 1; i != -1u; --i) {
		std::cin >> a[i];
		--a[i];
	}
	std::vector<u32> last(m, -1u);
	Tree t(n, m);
	for (u32 i = 0; i < n; ++i) {
		if (last[a[i]] == -1u) {
			if (i != 0) {
				t.setpar(i, i - 1);
			}
			t.setval(i, a[i]);
		} else {
			t.setpar(i, last[a[i]]);
		}
		last[a[i]] = i;
	}
	auto ans = t.getans();
	for (u32 i = 0; i < m; ++i) {
		std::cout << ans[i] << ' ';
	}
	std::cout << std::endl;
	return 0;
} // line 69 

// 这题很高质 

