#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

//#define DEBUG

#ifdef DEBUG
#define debug(fmt,...) printf(fmt,##__VA_ARGS__)
#else
#define debug(fmt,...)
#endif

/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

10 6
3 2 1 4 1 4 2 5 6 5

6 4
3 2 3 1 2 4
*/

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m;
	cin >> n >> m;
	vector <int> a(n + 1);
	vector <int> r(m + 1,0);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = n;i >= 1;i--) {
		if (r[a[i]] == 0) {
			r[a[i]] = i;
		}
	}
//	debug("--------------------------------------------------------------------------------------\n");

	vector <ll> ans(m + 1);
	for (int i = 1;i <= n;i++) {
		int j = i;
		while (j <= n) {
			ans[a[j]] += 1;
			j = r[a[j]] + 1;
		}
	}
	for (int i = 1;i <= m;i++) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}
