#include <bits/stdc++.h>

#define int long long 

using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], f[N], ans[N];
vector <pair <int, int> > k;
signed main() {
	
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		k.clear();
		memset (f, 0, sizeof f);
		for (int j = i; j <= n; j++) {
			if (f[a[j]]) {
			   bool flag = 0;
			   for (auto l : k)
			       if (f[a[j]] >= l.first && f[a[j]] <= l.second) {
			       	  flag = 1;
			       	  break;
				   } 
			   if(!flag) {
			   	   k.emplace_back (make_pair (f[a[j]], j - 1));
			   } else {
			   	   f[a[j]] = j;
			   }
			} else f[a[j]] = j;
	    }
	    for (int j = i; j <= n; j++) {
	    	bool flag = 0;
	    	for (auto l : k)
	    	    if (j >= l.first && j <= l.second) {
	    	       flag = 1;
	    	       break;
				}
			if (!flag) ans[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' '; 
	return 0;
}

