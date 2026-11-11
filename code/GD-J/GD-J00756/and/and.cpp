#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],dp[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	dp[1]=a[1];
	for(int i=2;i<=m;i++){
		dp[i]=max(dp[i],dp[i-1]&a[i]);
	}
	cout<<dp[m];
	return 0;
}
