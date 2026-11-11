#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, ans = 1;
int a[N], vis[N];
 
void dfs(int u, int cnt, int v){
	if (cnt > m) return;
	if (u > n) return;
	if (cnt == m){
		ans = max(ans, v);
		return;
	}
	if (!vis[u + 1]){
		vis[u + 1] = 1;
		dfs(u + 1, cnt + 1, v & a[u + 1]);
		dfs(u + 1, cnt, v);
	}
	vis[u + 1] = 0;
}
 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		dfs(i, 1, a[i]);
	}
	cout << ans;
	return 0;
}