#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], last[300005], ans[300005], siz[500005];
vector<int> vec[500005];

void dfs(int x){
	siz[x] = 1;
	for( int i : vec[x] ){
		dfs(i);
		siz[x] += siz[i];
	}
	ans[a[x]] += siz[x];
}

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for( int i = 1; i <= n; i++ ) cin >> a[i];
	for( int i = n; i >= 1; i-- ){
		if(!last[a[i]]) last[a[i]] = i;
		vec[last[a[i]] + 1].emplace_back(i);
	}
	dfs(n + 1);
	for( int i = 1; i <= m; i++ ) cout << ans[i] << ' ';
	return 0;
}
