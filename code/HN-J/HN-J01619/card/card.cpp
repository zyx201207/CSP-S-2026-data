#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,a[N],ans[N],lst[N],dp[N];
vector<int>e[N];
void dfs(int x){
	dp[x]=1;
	for(auto it:e[x]){
		if(!dp[it]){
			dfs(it);
			dp[x]+=dp[it];
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		e[lst[a[i]]+1].emplace_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=n;++i)ans[a[i]]+=dp[i];
	for(int i=1;i<=m;++i){
		if(i<m)cout<<ans[i]<<" ";
		else cout<<ans[i];
	}
	return 0;
}
