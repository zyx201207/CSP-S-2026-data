#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005]={};
long long dp[4002][4002]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++) dp[i][i]=a[i];
	for(int len=2;len<=m;len++){
		for(int i=1;i+len-1<=2*n-1;i++){
			int j=i+len-1;
			for(int k=i;k<j;k++){
				dp[i][j]=max(dp[i][j], dp[i][k]&dp[k+1][j]);
			} 
		}
	} 
	long long ans=0;
	for(int i=1;i+m-1<=2*n-1;i++){
		ans=max(ans,dp[i][i+m-1]);
	}
//	for(int i=1;i<=2*n;i++){
//		for(int j=1;j<=2*n;j++){
//			cout<<dp[i][j]<<'	';
//		}
//		cout<<'\n';
//	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
