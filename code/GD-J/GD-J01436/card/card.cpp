#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], ans[N];
bool f[N];
void solve () {
	stack<int> st;
	for (int k = 1; k <= n; k ++) {
		while (! st.empty ()) st.pop ();
		for (int i = k; i <= n; i ++) {
			if (f[a[i]]) {
				while (true) {
					int x = st.top ();
					st.pop ();
					f[a[x]] = false;
					if (x == a[i]) {
						break;
					}
				}
			}
			f[a[i]] = true;
			st.push (i);
			
		}
		for (int j = 1; j <= m; j ++) {
			if (f[j]) ans[j] ++;
			//cout << f[j] << ' ';
			f[j] = false;
		}
		//cout << '\n';
	}
	
	for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
}
void solve1 () {
	for (int i = 1; i <= n; i ++) {
		ans[a[i]] ++;
	}
	for (int i = 1; i <= m; i ++) {
		ans[i] = ans[i - 1] + ans[i];
		cout << ans[i] << ' ';
	}
}
void solve2 () {
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 1) {
			ans[1] = i;
		}
		else if ( a[i] == 2) {
			ans[2] = i;
		}
	}
	for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
}
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout); 
	cin >> n >> m;
	bool ck = true;
	for (int i= 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) ck = false;
	}
	if (n <= 500) {
		solve ();
		return 0;
	}
	if (ck) {
		solve1 ();
		return 0;
	}
	if (m <= 2) {
		solve2 ();
		return 0;
	}
	return 0; 
}
/*
test 1:

4 3 
1 2 1 3


test 2:

4 3
1 2 2 3


test 3:

5 2
1 2 1 1 2
*/
