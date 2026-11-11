#include <bits/stdc++.h>

using namespace std;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

bool mST;

namespace Main {

	const int N = 5e5 + 5;
	int n;
	ll m;
	ll a[N];
	__int128 s[N];
	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		cin >> n >> m;
		REP(i, 1, n) cin >> a[i];
		sort(a + 1, a + 1 + n);
		REP(i, 1, n) s[i] = s[i - 1] + a[i];
		// 不需要 __int128
		int ans=  0;
		REP(i, 1, n) {
			int l = 1, r = i, res = i;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if((__int128)(1) * (i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m) res = mid, r = mid - 1;
				else l = mid + 1;
			}
			ans = max(ans, i - res + 1);
			// cerr << res << '\n';
		}
		cout << ans << '\n';
		return 0; 
	}
}

bool mED;

int main() {
#ifndef Ace
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal.err", "w", stderr);
#endif
	Main::main();
	cerr << fixed << setprecision(3) << "Time: " << 1. * clock() / CLOCKS_PER_SEC << "s" << '\n';
	cerr << "static Memory: " << abs(&mST - &mED) / 1048576. << "mb" << '\n'; 
	return 0;
} 
/*
1s 1024M
*/