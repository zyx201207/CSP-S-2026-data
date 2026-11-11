#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000550],dp[2000055];
int n,d;
bool check(int f,int b,int c,int e){
	if(f<0)return 0;
	if(a[c]-a[f]<=d&&a[e]-a[b]<=d&&a[e]-a[f]>d)return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=n;i++){
		if(a[i]-a[i-1]>=d)dp[i]=dp[i-1];
		if(check(i-3,i-2,i-1,i)){
			dp[i]=1+dp[i-1]+dp[i-2];
			}
			else if(a[i]-a[i-3]<=d){
				dp[i]=dp[i-3]+dp[i-2];
			}
			else if(a[i]-a[i-2]>d){
				dp[i]=dp[i-1]+dp[i-3];
			}
			else {
				dp[i]=dp[i-1];
			}
			if(a[i]-a[i-2]>d&&a[i-1]-a[i-3]>d)dp[i]=dp[i-1];
		dp[i]=max(dp[i],dp[i-1]);
	}
	if(n<=3)cout<<0;
	else cout<<dp[n]<<'\n';
} 
return 0;
}
