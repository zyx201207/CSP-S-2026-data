#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int n, m;
int a[N];
int ans[N];
bool vis[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	
	for(int i = 1; i <= n; i ++) {
		memset(vis, false, sizeof vis);
		int lst = i;
		for(int j = i; j <= n; j ++) {
			if(!vis[a[j]]) {
				vis[a[j]] = true;
			} else {
				for(int k = i; k <= j; k ++) vis[a[k]] = false;
				vis[a[j]] = true;
			}
 		}
 		for(int j = 1; j <= m; j ++) if(vis[j]) ans[j] ++;
	}
	for(int i = 1; i <= m; i ++) cout << ans[i] << ' ';
	return 0;
}
