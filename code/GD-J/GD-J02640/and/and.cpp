#include<bits/stdc++.h>
using namespace std;
int n, m, maxn;
int ls[200005];
bool used[200005];
void dfs(int k, int res){
	if (res < maxn) return;
	if (k > m){
		maxn = max(maxn, res);
		return;
	}
	for (int i = 1;i <= n; ++ i){
		if (used [ i ]) continue;
		used [ i ] = true;
		dfs(k + 1, res & ls [ i ]);
		used [ i ] = false;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1;i <= n; ++ i) cin >> ls [ i ];
	sort(ls + 1, ls + n + 1, greater<int>());
	dfs(1, INT_MAX);
	cout << maxn << "\n";
	return 0;
}
