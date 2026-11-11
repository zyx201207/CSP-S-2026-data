#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
	int l, r;
} b[2000005];
int Caseid, t, n, d, a[2000005], w[2000005], w1[2000005];
bool mark[2000005];
vector<int> v[2000005];
void dfs(int u) {
	if (mark[u]) {
		return;
	}
	mark[u] = true;
	// if (u == n) {
	// 	w[u] = 1;
	// 	return;
	// }
	if (u == 1) {
		w[u] = max(0ll, b[u].r - u);
	} else {
		w[u] = b[u].r - u;
		if (b[u - 1].r >= u) {
			w[u] = b[u].r - b[u - 1].r;
		}
	}
	w[u] ++;
	if (b[u].r == u) {
		// w[u] = 1;
	// 	// w[u] ++;
	// 	// if (u != 1) {
	// 	// 	w[u] -= (b[u - 1].r == b[u].r);
	// 	// }
	// 	//  else {
	// 	// 	w[u] --;
	// 	// }
		return;
	}
	// w[u] = max(0ll, b[u].r - u);
	// if (u != 1) {
	// 	w[u] -= max(0ll, b[u - 1].r - u);
	// 	w[u] = max(0ll, w[u]);
	// }
	dfs(b[u].r);
	w[u] += max(0ll, w[b[u].r] - 1);
	// w[u] ++;
	// if (u != 1) {
	// 	w[u] -= (b[u - 1].r == b[u].r);
	// } 
	// else {
	// 	w[u] --;
	// }
}
void dfs1(int u) {
	if (mark[u]) {
		return;
	}
	mark[u] = true;
	// if (u == 1) {
	// 	w1[u] = 0;
	// 	return;
	// }
	if (u == n) {
		w1[u] = max(0ll, u - b[u].l);
	} else {
		w1[u] = u - b[u].l;
		if (b[u + 1].l < u) {
			w1[u] = b[u + 1].l - b[u].l;
		}
	}
	w1[u] ++;
	if (b[u].l == u) {
		// w1[u] = 0;
		// w1[u] ++;
		// if (u != n) {
		// 	w1[u] -= (b[u + 1].l == b[u].l);
		// }
		//  else {
		// 	w1[u] --;
		// }
		return;
	}
	// w1[u] = max(0ll, u - b[u].l);
	// if (u != n) {
	// 	w1[u] -= max(0ll, u - b[u + 1].l);
	// 	w1[u] = max(0ll, w1[u]);
	// }
	dfs1(b[u].l);
	w1[u] += max(0ll, w1[b[u].l] - 1);
	// w1[u] ++;
	// if (u != n) {
	// 	w1[u] -= (b[u + 1].l == b[u].l);
	// } 
	// else {
	// 	w1[u] --;
	// }
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> Caseid >> t;
	while (t --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i ++) {
			b[i].l = lower_bound(a + 1, a + 1 + n, a[i] - d) - a;
			b[i].r = upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
			b[i].l = min(b[i].l, i);
			b[i].r = max(b[i].r, i);
			// v[b[i].l].push_back(i);
			// cerr << b[i].l << " " << b[i].r << "\n";
		}
		for (int i = 1; i <= n; i ++) {
			int l = b[i].r, r = n, mid = (l + r) >> 1, pos = -1;
			while (l <= r) {
				if (b[mid].l < b[i].r - 1) {
					l = mid + 1;
					mid = (l + r) >> 1;
				} else {
					if (b[mid].l == b[i].r - 1) {
						pos = mid;
					}
					r = mid - 1;
					mid = (l + r) >> 1;
				}
			}
			// for (int j = l; j <= n; j ++) {
			// 	if (b[j].l == b[i].r - 1) {
			// 		pos = j;
			// 		break;
			// 	}
			// }
			// cerr << pos << " ";
			while (pos != -1 && b[pos].l == b[i].r - 1) {
				if (pos != i && b[i].r != pos && b[pos].l != i) {
					v[i].push_back(pos);
					// cerr << pos << " ";
				}
				pos ++;
			}
			// cerr << "\n";
		}
		for (int i = 1; i <= n; i ++) {
			if (!mark[i]) {
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i ++) {
			mark[i] = false;
		}
		for (int i = 1; i <= n; i ++) {
			if (!mark[i]) {
				dfs1(i);
			}
			// w[i] ++;
			// if (i != 1) {
			// 	w[i] -= (b[i - 1].r != b[i].r);
			// } else {
			// 	w[i] --;
			// }
			// w1[i] ++;
			// if (i != n) {
			// 	w1[i] -= (b[i + 1].l != b[i].l);
			// } else {
			// 	w1[i] --;
			// }
			cerr << w[i] << " " << w1[i] << "\n";
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			// cerr << i << ":\n";
			for (auto j : v[i]) {
				ans += w1[i] * w[j];
				// ans += w[j];
				// cerr << j << " ";
			}
			// cerr << "\n";
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; i ++) {
			v[i].clear();
			w[i] = 0;
			w1[i] = 0;
			mark[i] = false;
		}
	}
	cerr << "Time elapsed:" << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
6 3
0 1 2 3 4 7

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/