#include<bits/stdc++.h>
using namespace std;
struct DP{
	int cost,sum;
}dp[500005],dpnew[500005];
int n,m,a[500005];
bool cmp(DP x,DP y){
	return x.sum>y.sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1].cost=0,dp[1].sum=1;
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])*(i-1)+dp[i-1].cost<=m)
		dp[i].cost=(a[i]-a[i-1])*(i-1)+dp[i-1].cost,dp[i].sum=dp[i-1].sum+1;
		else if(a[i-dp[i-1].sum+1]-a[i-dp[i-1].sum]>a[i]-a[i-1])
		dp[i].cost=(a[i]-a[i-1])*(i-1)+dp[i-1].cost-a[i-dp[i-1].sum+1]-a[i-dp[i-1].sum]+a[i]-a[i-1];
		else dp[i].cost=0,dp[i].sum=1;
	}
//	int areabegin=1,areaend;bool next=false;
//	for(int i=2;i<=n;i++){
//		if(!next&&dp[i].cost==0)areaend=i,next=1;
//		else if(dp[i].cost==0)areabegin=areaend,areaend=i;
//		
//	}
//	for(int i=1;i<=n;i++)cout<<dp[i].cost<<' '<<dp[i].sum<<endl;
	sort(dp+1,dp+n+1,cmp);
	cout<<dp[1].sum;
}