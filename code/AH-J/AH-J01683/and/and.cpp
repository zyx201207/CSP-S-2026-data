#include <bits/stdc++.h>
using namespace std;
int n, m, vis[200005], ans, a[200005];
void dfs(int d, int step, int cnt){
	if(step){
		dfs(d, step-1, cnt&a[d]);
	} 
	else{
		d--;
		ans=max(ans, cnt);
		return ;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=n; i>=m; i--){
		memset(vis, 0, sizeof(vis));
		vis[i]=1;
		dfs(i, m-1, a[i]);
		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}/*
#include <bits/stdc++.h>
using namespace std;
int n, m, ans, dp[20005][20005], a[20005];
int main(){
//	freopen("and.in", "r", stdin);
//	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, 0, sizeof(dp));
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		dp[i][1]=a[i];
		for(int t=2; t<=min(i, m); t++){
			for(int j=1; j<i; j++){
				dp[i][t]=max(dp[i][t], dp[i][t-1]&a[j]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	for(int i=1; i<=n; i++){
		if(ans<dp[i][m]) ans=dp[i][m];
	}
	cout<<ans;
	return 0;
}
*/
