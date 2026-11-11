#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3+10;
ll n,m,a[N],dp[500010][N],ans = -1,b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n-1){
		for(int i = 1;i<=n;i++){
			b[i] = a[i];
			b[i]&=b[i-1];
		}
		for(int i = 1;i<=n;i++){
			ans = max(ans,b[n]|a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(ll i = 1;i<=n;i++){
		dp[i][1] = max(a[i],dp[i-1][1]);
	}
	for(ll i = 1;i<=n;i++){
		for(ll j = 2;j<=min(i,m);j++){
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	for(ll i = 1;i<=n;i++){
		ans = max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
