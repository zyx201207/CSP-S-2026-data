#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005];
long long maxx,ans;
bool b[25];
void dfs(int k,long long num){
	if(k==m+1){
		maxx=max(maxx,num);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			if(k==1) dfs(k+1,a[i]);
			else dfs(k+1,num&a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	else if(m>=n-1){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx&=a[i];
		}
		if(m==n) cout<<maxx;
		else{
			for(int i=1;i<=n;i++){
				ans=max(ans,maxx&a[i]);
			}
			cout<<ans;
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(n<=20){
		dfs(1,0);
		cout<<maxx;
	}else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dp[j]=max(dp[j],dp[i-1]&a[j]);
			}
		}
		cout<<dp[m];
	}
	return 0;
}
