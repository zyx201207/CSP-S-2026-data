#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],m,dp[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=a[i];
	}
	if(n>2000){
		sort(a+1,a+n+1,greater<ll>());
		cout<<a[m];
		return 0;
	}
	ll ans=-1e18;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			for(int k=1;k<i;k++){
				dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
			}
			if(j==m) ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;
	return 0;
}
