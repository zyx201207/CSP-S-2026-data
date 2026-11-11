#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005],use[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i==j)continue;
		if(a[i]&a[j]>maxn){
			maxn=a[i]&a[j];
			use[i]=1;
			use[j]=1;
		}
	}
	dp[1]=maxn;
	for(long long i=2;i<=m;i++){
		for(long long j=1;j<=n;j++){
			dp[i]=dp[i-1];
			if(!use[j])
				dp[i]=max(dp[i],dp[i-1]&a[j]);
		}
		for(long long j=1;j<=n;j++){
			if(dp[i]==dp[i-1]&a[j])
			use[j]=1;
		}
	}
	cout<<dp[m];
}
