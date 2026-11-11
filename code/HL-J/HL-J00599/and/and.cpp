#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=2e5+17;
ll n,m,a[M];
struct pr{
	ll mx,sm,q;
}dp[M];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll p=-22222;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p=max(p,a[i]);
	}if(m==1){
		cout<<p;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	ll ag=-222;
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ag=max(ag,a[i]&a[j]);
			}
		}cout<<ag;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+1+n);
	dp[1]={a[1],1,1};
	for(int i=2;i<=n;i++){
		ll _=(dp[i-1].sm<m?a[i]&dp[i-1].mx:-1);
		if(a[i]>dp[i-1].mx&&a[i]>_){
			dp[i]={a[i],1,1};
		}else if(_>a[i]&&_>dp[i-1].mx){
			dp[i]={_,dp[i-1].sm+1,(dp[i-1].q+1<=m?dp[i-1].q+1:dp[i-1].sm+1)};
		}else if(dp[i-1].mx>_&&dp[i-1].mx>a[i]){
			dp[i]=dp[i-1];
		}else if(a[i]==_){
			dp[i]={a[i],1,(dp[i-1].q+1<=m?dp[i-1].q+1:1)};
		}else if(a[i]==dp[i-1].mx){
			dp[i]={a[i],1,dp[i-1].q};
		}else if(dp[i-1].mx==_){
			dp[i]={a[i],dp[i-1].q,(dp[i-1].q+1<=m?dp[i-1].q+1:dp[i-1].q)};
		}
	}bool flag=1;
	for(int i=n;i>=1;i--){
		if(dp[i].sm==m||dp[i].q==m){
			cout<<dp[i].mx;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}if(dp[i].q!=1)flag=false;
	}if(flag)cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

