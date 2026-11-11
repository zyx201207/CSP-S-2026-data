#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a[maxn], ans[maxn], lst[maxn], vis[maxn];
vector<int> ve[maxn];
void dfs(int x) {
	ans[x] = 1;
	for(int i = 0; i < ve[x].size(); i++) {
		dfs(ve[x][i]);
		ans[x] += ans[ve[x][i]];  
	}
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--) {
		if(!vis[a[i]]) ve[i + 1].push_back(i), vis[a[i]] = lst[a[i]] = i; 
		else ve[lst[a[i]]].push_back(i), lst[a[i]] = i;
	} 
	dfs(n);
	for(int i = 1; i <= m; i++) cout << ans[vis[i]] << " ";
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--) solve();
	return 0;
}

