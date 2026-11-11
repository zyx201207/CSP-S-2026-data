#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10, M = 5e5+10;
int n, m, a[N], b[N], pos[M];
int dp[N], sum[N], ans[M];
vector<int> g[N];
void dfs(int u){
	sum[u] = 1;
	for(int x:g[u]){
		dfs(x); sum[u] += sum[x];
	}
	if(!dp[u]) b[u] = sum[u];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=n;i;i--){
		if(pos[a[i]]) {
			dp[i] = pos[a[i]];
			g[pos[a[i]]].push_back(i);
		}else g[i+1].push_back(i);
		pos[a[i]] = i;
	}
	for(int i=n;i;i--){
		if(!sum[i] && g[i].size()) dfs(i);
	}
	for(int i=1;i<=n;i++) ans[a[i]] += b[i];
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
} 
