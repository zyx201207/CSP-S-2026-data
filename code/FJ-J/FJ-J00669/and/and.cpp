#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[6005][6005],ans,b[200005],sum;

void dfs(int step,int sum){
	if(step>m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		b[i]=1;
		dfs(step+1,sum&a[i]);
		b[i]=0; 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n,[](int x,int y){return x>y;});
	
	if(m<=20){
		sum=2147483647;
		dfs(1,sum);
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<a[1];	
		return 0;
	}
	if(m==2&&n<=6000){
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(a[i]<=ans||a[j]<=ans)break;
				int sum=a[i]&a[j];
				ans=max(ans,sum);
			}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}
	
	long long ans=a[1];
	for(int i=1;i<=m;i++)
		ans=ans&a[i];	
	cout<<ans;
	
	
	
	/*
	for(int i=0;i<=n;i++)
		dp[i][0]=dp[i][1]=2147483647;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j>i)continue;
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i][j]);
		}
			
	}
	cout<<dp[n][m];
	*/
}
