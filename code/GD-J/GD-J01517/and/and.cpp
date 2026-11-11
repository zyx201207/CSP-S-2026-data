#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000+10;
ll n,m,a[N],dp[2010][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2&&n<=2000){
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	dp[0][0]=(1<<30)-1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i][m]);
	cout<<ans;
	return 0;
}
