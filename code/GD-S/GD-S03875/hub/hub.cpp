#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6+3;
vector<int> G[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T >> _T;
//	auto count1 = [](int x)->int {
//		int res = 0;
//		for(; x; x >>= 1)
//			res += (x&1);
//		return res;
//	};
	for(int n, k; _T--; ) {
		cin >> n >> k;
		for(int _ = 1, u, v; _ < n; ++_) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
//		for(int S = 1; S < 1<<n; ++S) {
//			if(count1(S) != k)
//				continue;
//			vector<int> a;
//			for(int i = 0; i < n; ++i)
//				if(S>>i & 1)
//					a.push_back(i+1);
//		}
		cout << n/2+(n%2);
		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}
	return 0;
}