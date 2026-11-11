#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long dp[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[2]-a[1]==a[3]-a[2] || n==2){
		dp[1]=dp[2]=1;
		for(long long i=3;;i++){
			if(dp[i-1]>=m){
				cout<<min(i-1,n);
				break;
			}
			dp[i]=dp[i-1]+dp[i-2];
		}
	}
	else{
		if(m%2==1) cout<<n/2+1;
		else cout<<n/2;
	}
	return 0;
}
