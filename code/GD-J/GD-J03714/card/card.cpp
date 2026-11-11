#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], v[N], ans[N];
bool mp[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int tot, st = 1; st <= n; ++st) {
		tot = 0;
		for(int i = 1; i <= m; ++i)
			mp[i] = false;
		for(int i = st; i <= n; ++i) {
			if(mp[a[i]])
				while(tot > 0) {
					int x = v[tot];
					mp[x] = false;
					-- tot;
					if(x == a[i])
					break;
				}
			v[++ tot] = a[i];
			mp[a[i]] = true;
		}
		for(int i = 1; i <= tot; ++i)
			++ ans[v[i]];
	}
	for(int i = 1; i <= m; ++i)
		cout << ans[i] << " ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

48 pts ?
бл 
*/
