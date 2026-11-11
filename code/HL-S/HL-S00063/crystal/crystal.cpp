#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],dp[500010][2];
int main(){
	int n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
//		cout<<b[i]<<" ";
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<m;j++){
//			if(j-b[i]>=0){
//				dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i]]+1);
//			}
//		}
//	}
	for(int i=0;i<=n;i++){
		dp[i][1]=m;
		dp[i][0]=1;
	}
	long long maxn=0;
	for(int i=1;i<=n;i++){
		if(dp[i-1][1]-b[i]*dp[i-1][0]>=0){
			if(dp[i-1][0]<=dp[i-1][0]+1){
				dp[i][1]=dp[i-1][1]-b[i]*dp[i-1][0];
				dp[i][0]=dp[i-1][0]+1;
			}else{
				dp[i][1]=dp[i-1][1];
				dp[i][0]=dp[i-1][0];
			}
		}
		maxn=max(maxn,dp[i][0]);
	}
	cout<<maxn;
	return 0;
}
