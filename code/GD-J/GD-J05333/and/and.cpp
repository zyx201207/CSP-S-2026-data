#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m,a[200010],dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++)
			dp[i]=max(max(dp[i-1]&a[i],dp[i]),a[i]);
	}
	cout<<dp[n];
	return 0;
}
