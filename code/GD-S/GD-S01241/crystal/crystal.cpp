#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];
long long dp[500010];
long long qzh[500010];
long long ans=0;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1]=1;
	for(int i=2;i<=n;i++){
		qzh[i]=(a[i]-a[i-1])*dp[i-1]+qzh[i-1];
		dp[i]=dp[i-1]+1;
		if(qzh[i]<=m) continue;
		else{
			while(qzh[i]>m){
				qzh[i]-=(a[i]-a[i-dp[i-1]]);
				dp[i]--;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(dp[i]>ans) ans=dp[i];
	}
	cout<<ans;
	return 0;
}

