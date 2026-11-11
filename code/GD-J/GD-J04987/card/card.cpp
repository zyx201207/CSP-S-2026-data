#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,m,a[maxn],lst[maxn],num[maxn],dp[maxn];
vector<int>g[maxn];
void dfs(int x){
	dp[x]=num[x];
	for(auto y:g[x]){
		dfs(y);
		dp[x]+=dp[y];
	}
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],num[a[i]]++;
	for(int i=n;i>=1;i--){
		if(!lst[a[i]]){
			lst[a[i]]=i;
			g[a[i+1]].push_back(a[i]);
		}
	}
	dfs(0);
	for(int i=1;i<=m;i++)cout<<dp[i]<<" ";
	return 0;
}
