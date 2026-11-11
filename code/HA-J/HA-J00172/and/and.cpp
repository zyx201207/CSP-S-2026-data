#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 6e6 + 5;
int n, m, ans, a[N], vis[N];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for (int j = 30; j >= 0; --j){
		int cnt = 0;
		for (int i = 1; i <= n; ++i){
			if (vis[i])continue;
			if ((a[i] >> j) & 1){
				++cnt;
			}
		}
		if (cnt >= m){
			ans |= (1 << j);
			for (int i = 1; i <= n; ++i){
				if (vis[i])continue;
				if (!((a[i] >> j) & 1)){
					vis[i] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
/*
这个题真的比 t2 简单吧。
为啥我刚开始没会 t2 贪心暴力。
dp 是错的。
神了。 
*/ 
