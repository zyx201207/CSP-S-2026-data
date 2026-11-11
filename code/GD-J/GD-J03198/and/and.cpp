#include <bits/stdc++.h>
#define int long long
#define rd read()
using namespace std;
inline int read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
const int N = 2e5 + 5;
int n, m, a[N], ans;
vector<int> v;
signed main() {
	freopen("and.in", "r", stdin), freopen("and.out", "w", stdout);
	n = rd, m = rd;
	for (int i = 1; i <= n; ++i) a[i] = rd, v.push_back(a[i]);
	for (int i = 30; ~i; --i) {
		vector<int> d;
		for (int j : v) if (j >> i & 1) d.push_back(j);
		if (d.size() >= m) {
			ans += (1 << i);
			v.clear(); for (int j : d) v.push_back(j); 
		}
	}
	cout << ans;
	return 0;
}
