#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,gs,ans=-1;
long long a[500010];
long long c[500010];
long long dp[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		gs++;
		sum=dp[i-1]+gs*c[i];
		if(sum>m){
//			cout<<i<<' ';
			sum=0;
			dp[i]=0;
			gs=0;
		}else{
			dp[i]=sum;
			if(gs>ans){
				ans=gs;
			}
		}
//		cout<<dp[i]<<' ';
	}
	cout<<ans+1;
	return 0;
}
