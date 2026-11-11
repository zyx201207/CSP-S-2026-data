#include<bits/stdc++.h>
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int N = 1e5 + 5;
const db EPS = 1e-6;
const int MOD = 998244353;
const ull P = 33550337;

inline int lowbit(int x) {
	return (x & (-x));
}

struct random_system{
ull seed = 1LL*97324986237;
inline ull getrand() {
	seed ^= (seed >> 17);
	seed ^= (seed << 5);
	seed ^= (seed << 13);
	return seed;
}
} rds;

int c, T, n, k;

int main() {
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		rds.seed += n + k + 2077;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			rds.seed += (u * v ^ 13579);
		}
		cout << (rds.getrand() + T - 1) % (n / 2) + 1 << "\n";
	}
	
	return 0;
}
