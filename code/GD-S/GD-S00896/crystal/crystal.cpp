#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long dp[5000][10000];
long long ans=0,av=0,k=0;
void solve(){
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(m<sum) break;
		ans++; 
	}
	cout<<ans;
}
void solve1(){
	av/=n;
	for(int i=1;i<=n;i++){
		if(abs(av-a[i])<=abs(av-a[k])&&k<i) {
			k=i;
		}
	}
	for(int i=1;i<=n;i++){
		 dp[i][0]=dp[i-1][0];
		 if(a[i]==k) dp[i][0]++; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i-1][j];
   			if(j>=abs(a[k]-a[i])) dp[i][j]=max(dp[i][j],dp[i][j-abs(a[k]-a[i])]+1);	
		}
	}
	cout<<dp[n][m];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		av+=a[i];
	}
	sort(a+1,a+n+1); 
	if(n>=5000){
		solve();
	}
	else {
		solve1();
	}
	return 0;
}
