#include <bits/stdc++.h>
#define int long long
#define F(i, s, t) for (int (i) = (s); (i) <= (t); ++(i))
#define outs(s) cout << (s) << ' '
#define outn(s) cout << (s) << '\n'
#define FILENAME "card"
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	
	const int N = 5e5+5;
	const int M = 3e5+5;
	int n, m, a[N], nxt[M], ans[M];
	cin >> n >> m;
	F(i, 1, n) {
		cin >> a[i];
	}
	F(i, 1, m) {
		nxt[i] = -1;
	}
	for (int i = n; i >= 1; --i) {
		if (nxt[a[i]] == -1) {
			nxt[a[i]] = i;
		}
	}
	F(i, 1, n) {
		F(j, i, n) {
			if (nxt[a[j]] != j) {
				j = nxt[a[j]];
			}
			ans[a[j]]++;
		}
	}
	
	F(i, 1, m) {
		cout << ans[i] << ' ';
	}
	
	return 0;
} 
