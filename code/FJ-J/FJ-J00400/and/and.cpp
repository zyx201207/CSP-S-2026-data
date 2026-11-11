#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
bool vis[N];
int ans = 0;
int maxn = -1;
int lst = 0;
void dfs(int x) {
	if(x == m + 1) {
		maxn = max(ans, maxn);
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			lst = ans;
			ans = (a[i] & ans);
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
			ans = lst;
		}
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) {
		ans = a[i];
		vis[i] = 1;
		dfs(2);
		vis[i] = 0;
	}
	cout << maxn << '\n';
	return 0;
}

