#include<bits/stdc++.h>
using namespace std;
long long n,m,ma;
long long a[600050],dp[600050],c[600050];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1]=1;
	c[1]=0;
	for(long long i=2;i<=n;i++){
		c[i]=c[i-1]+dp[i-1]*(a[i]-a[i-1]);
		dp[i]=dp[i-1]+1;
		while(c[i]>m){
			c[i]-=a[i]-a[i-dp[i]+1];
			dp[i]--;
		}
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		if(ma<dp[i]) ma=dp[i];
	}
	cout<<ma;
	return 0;
} 
