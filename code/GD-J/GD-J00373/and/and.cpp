#include <bits/stdc++.h>
#define int long long
#define F(i, s, t) for (int (i) = (s); (i) <= (t); ++(i))
#define outs(s) cout << (s) << ' '
#define outn(s) cout << (s) << '\n'
#define FILENAME "and"
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	
	set<int> a;
	a.clear();
	//const int N = 2e5+5;
	int m, n, x;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		a.insert(x);
	}
	
	for (int i = 30; i >= 0; --i) {
		int cnt = 0;
		for (auto j : a) {
			//outs(j);
			if ((j & (1 << i))) {
				//outs('!');
				cnt++;
			}
		}
		outs(i);
		outn(cnt);
		if (cnt >= m) {
			for (auto j : a) {
				if (!(j & (1 << i))) {
					outs("erase");
					outs(j);
					outs(j);
					outn(j);
					if (a.count(j) == 0) {
						cerr << "!!!!!";
						return 0;
					}
					a.erase(j);
				}
			}
		}
	}
	int ans = INT_MAX;
	for (auto i : a) {
		ans = ans & i;
	}
	cout << ans;
	
	return 0;
} 
