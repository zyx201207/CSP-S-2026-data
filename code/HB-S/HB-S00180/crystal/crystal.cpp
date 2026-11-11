#include<bits/stdc++.h>
using namespace std;
int n,dp[500005];
long long a[500005],num[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	dp[1]=1;
	num[1]=m;
	for(int i=2;i<=n;i++){
		long long ned=num[i-1];
		ned-=dp[i-1]*(a[i]-a[i-1]);
		dp[i]=dp[i-1]+1;
		if(ned>=0){
			num[i]=ned;
			continue;
		}
		while(ned<0){
			dp[i]--;
			ned+=a[i]-a[i-dp[i]];
		}
		num[i]=ned;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	cout << ans;
	return 0;
}
/*
tanxin
especially,the number can only be added.
so,if we want to use the number a[i],we can only choose number form a[1] to a[i].
*/
