#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,ans;
int x[2000005],dp[2000005],b[2000005];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		dp[i]=min(dp[i-1]+1,dp[i-2]+1);
	}
	cout<<dp[n]<<endl;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
