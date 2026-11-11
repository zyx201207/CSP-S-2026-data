#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, maxn = 0, ans = 0, a[200005], o[200005], vis[200005];

void dfs(int x, int xorr){
	if (xorr == 0) return ;
	if (x > m){
		ans = max(ans, xorr);
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		vis[i] = 1;
		o[x] = a[i];
		dfs(x + 1, (xorr & a[i]));
		vis[i] = 0;
	}
}

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
//		for (int j = 0; ; j++){
//			long long pow = 1 << j;
//			if (pow > a[i]) break;
//			if ((a[i] & pow) > 0) o[i]++;
//		}
	}
	if (m == 1){
		cout << maxn;
	}else{
		dfs(1, pow(2, 30) - 1);
		cout << ans;
	}
	return 0;
}
