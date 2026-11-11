#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200005];
long long dp[200005];
void dfs(int cnt,long long sum,int stp){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(stp==n+1){
		return;
	}
	dfs(cnt+1,sum&a[stp],stp+1);
	dfs(cnt,sum,stp+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,a[i],i+1);
	}
	cout<<ans;
	return 0;
}
