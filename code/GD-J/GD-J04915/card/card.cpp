#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N(5e5+5);
int n,m;
int a[N],vis[N],dp[N];
vector<int>e[N];
void dfs(int u,int p){
	for(int v:e[u]){
		dfs(v,u);
		dp[u]+=dp[v];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) dp[cin>>a[i],a[i]]++;
	for(int i=n;i;--i) if(!vis[a[i]]++) e[a[i+1]].push_back(a[i]);
	dfs(a[n],0);
	for(int i=1;i<=m;++i) cout<<dp[i]<<' ';
}
