#include<bits/stdc++.h>
using namespace std;
int n,m,flag1,flag2,tmp;
long long a[500005],dp[500005],sum[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ans=1,flag1=1,flag2=1;
	for(int i=1;i<=n;i++) dp[i]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2) tmp=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=tmp) flag1=0;
		if(a[i]!=i) flag2=0;
	}
	sort(a+1,a+n+1);
	if(flag2){
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]+(i-1);
			if(sum[i]>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(flag1){
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
			if(sum[i]>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(sum[j]+(a[i]-a[j])*j<=m&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				sum[i]=sum[j]+(a[i]-a[j])*j;
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
