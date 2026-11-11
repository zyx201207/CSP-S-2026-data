#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e3+10;
long long a[maxn],dp[maxn][maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
//	if(n>2000){
//		int mul=1,ans=0;
//		while(n!=0){
//			n/=2;
//			ans+=mul;
//			mul*=2;
//		}
//		cout<<ans;
//		return 0;
//	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<=n;i++){
		dp[i][0]=-1;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			for(long long k=0;k<i;k++){
				dp[i][j]=max(dp[i][j],(dp[k][j-1]&a[i]));
			}
//			cout<<dp[i][j]<<" ";
		}
//		cout<<"\n";
	}
	cout<<dp[n][m];
}
