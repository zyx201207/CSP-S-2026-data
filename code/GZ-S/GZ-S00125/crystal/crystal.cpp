//GZ-S00125 曹讯  贵阳市第一中学 
//crystal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500050],num[500050];
ll dp[500050][2],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 	num[a[i]]++;
	}
	sort(a+1,a+n+1);
	dp[0][0]=0;
	dp[0][1]=m;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][1];
			continue;
			
		}
		if(dp[i-1][1]-abs(a[i]-a[i-1])<0){
			dp[i][0]=num[a[i]];
			dp[i][1]=dp[i-1][1];
//			cout<<dp[i][0]<<"---------"<<dp[i][1]<<"--------"<<endl;
			continue;
		}
		ll kyh;
		if((dp[i-1][1]/abs(a[i]-a[i-1]))>=dp[i-1][0]){
			kyh=dp[i-1][0];}
		else{kyh=dp[i-1][1]/abs(a[i]-a[i-1]);	}
		dp[i][0]=num[a[i]]+kyh;
		dp[i][1]=dp[i-1][1]-kyh*abs(a[i]-a[i-1]);
//		cout<<dp[i][0]<<"---------"<<dp[i][1]<<"--------"<<endl;
		if(ans<=dp[i][0]){
		 	ans=dp[i][0];}	
	} 
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

