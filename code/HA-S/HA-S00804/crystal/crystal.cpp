#include <bits/stdc++.h>
#define fi first
#define se second
#define pq priority_queue

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using db = double;
using pii = pair<int, int>;
//bool m1;
//namespace Debug {
//	db Tbegin, Tend;
//	#define M() cerr << (&m2 - &m1) / 1024 / 1024 << "MB " << (&m2 - &m1) / 1024 << "KB\n"
//	#define Tbegin() Tbegin = (db)clock()
//	#define Tend() Tend = (db)clock()
//	#define T() cerr << Tend - Tbegin << "ms " << (Tend - Tbegin) / CLOCKS_PER_SEC << "s\n"
//	#define de(x) cerr << #x << " = " << x << '\n' 
//} using namespace Debug;

const int N = 510000;
int n, ans;
ll m, s[N];

inline bool check(int idx, int x) {
	ll tot = (s[idx] - s[idx - 1]) * (idx - x + 1);
	tot -= s[idx] - s[x - 1];
	return tot <= m;
}

//bool m2;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
	sort(s + 1, s + n + 1);
	for (int i = 1; i <= n; i++) s[i] += s[i - 1];
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i;
		for (; l + 1 < r; ) {
			int mid = (l + r) / 2;
			if (check(i, mid)) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	printf("%d\n", ans);
	return 0;
}