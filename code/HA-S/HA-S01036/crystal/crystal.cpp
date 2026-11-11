#include <bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int a[N];
int dp[N];
int lenn;
int ans=0;
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int lenn=(n+1)/2;
//	for (int i=1;i<=n;i++){
//    	if (a[i]<a[lenn]){
//    		dp[i]=max(dp[i-1],dp[i-1]+a[lenn]-a[i]);
//		}
//		else{
//			dp[i]=max(dp[i-1],dp[i-1]+a[i]-a[lenn]);	
//		}
//		m-=abs(a[i]-a[lenn]);
//		if (m<=0){
//			break;
//		}
//	}
//	for (int i=1;i<=n;i++){
//		cout<<dp[i];
//	}	
//	cout<<dp[n];
    for (int i=1;i<=n;i++){
    	if (a[i]<a[lenn]){
    		a[i]=a[lenn];
    		m-=(a[lenn]-a[i]);
		}
		if (m<=0){
			break;
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i]==a[lenn]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
