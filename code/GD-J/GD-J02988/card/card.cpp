#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005, MAXM = 300005;
int n, m, a[MAXN], ans[MAXM], last[MAXN], val[MAXN];
bool vis[MAXN];
vector<int> e[MAXN];
//bool vis[MAXN];
//void dfs(int u, int fa){
//	vis[u] = 1;
//	for(int v :  e[u]){
//		if(v == fa) continue;
//		val[v] = val[u] + 1;
//	}
//}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
//		eff[i] = i;
	}
	
	for(int i = 1; i < n; i++){
		if(a[i] > a[i + 1]) flag = 0;
	}
	if(flag){
		ans[a[n]] = n;
		for(int i = n - 1; i >= 1; i--){
			if(a[i] != a[i + 1]){
				ans[a[i]] = i;
			}
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i] << ' '; 
		}
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cout << 0;
	}
	return 0;
//	for(int i = 1; i <= n; i++){
//		last[a[i]] = i;
//	}
//	for(int i = n; i >= 1; i--){
//		if(last[a[i]] == i || last[a[i]] == n){
//			continue;
//		}
//		e[last[a[i]] + 1].push_back(i);
//	}
//	for(int i = 1; i <= n; i++){
//		if(!vis[i]){
//			val[i] = 0;
//			dfs(i, 0);
//		}
//	}
	return 0;
}
