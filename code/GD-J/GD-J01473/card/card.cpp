#include <bits/stdc++.h>
using namespace std;
#define up(i, a, b) for(int i = a; i <= b; i++)
#define dn(i, a, b) for(int i = a; i >= b; i--)
#define VI vector <int>
const int NN = 2e5 + 10;
int has[NN];
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	VI a(n + 1);
	up (i, 1, n) cin >> a[i];
	map <int, int> ap;
	up (rod, 1, n) {
		VI st;
		up (i, rod, n) has[a[i]] = 0;
		up (i, rod, n) has[a[i]]++;
		up (i, rod, n) {
			int cur = a[i];
			if (has[cur] >= 1) {
				st.push_back(cur);
				has[cur]--;
				while (has[cur] >= 1) {
					has[a[++i]]--;
				}
			}
			else {
				st.push_back(cur);
				has[cur] ++;
			}
		}
		for (auto i : st) ap[i]++;
	}
	up (i, 1, m) cout << ap[i] << ' ';
	return 0;
}

