#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int dp[N][N];
int a[N];
int ans=0;
int n,m;
void dfs(int step,int lim,int sum){
	if(step==n+1){
		if(lim==m)ans=max(ans,sum);
		return ;
	}
	if(lim==m){
		ans=max(ans,sum);
		return ;
	}
	if(lim>m)return ;
	dfs(step+1,lim,sum);
	sum=sum^a[step];
	dfs(step+1,lim+1,sum);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20&&m<=n){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}else if(m==1){
		int tmp=0;
		for(int i=1;i<=n;i++){
			tmp=max(tmp,a[i]);
		}
		cout<<tmp;
		return 0;
	}else if(m==n){
		int tmp=a[1];
		for(int i=2;i<=n;i++){
			tmp=tmp^a[i];
		}
		cout<<tmp;
		return 0;
	}else if(m==2){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	else{
		dp[1][1]=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[i][j]=dp[i-1][j-1]^a[i];
				dp[i][j-1]=dp[i-1][j-1];
			}
		}
		cout<<dp[n][m];
	}
}
