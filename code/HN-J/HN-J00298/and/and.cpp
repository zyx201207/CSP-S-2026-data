#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200500;
int n,m,a[N],dp[N];
signed main()
{

	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>> n >> m;
	for (int i=1;i<=n;i++){
		cin>> a[i];
	}
	for (int i=1;i<n;i++){
		dp[1]=max(dp[1],a[i]);
		for (int j=i+1;j<=n;j++){
			dp[2]=max(dp[2],a[i]&a[j]);
		}
	}
	for (int i=3;i<=m;i++){
		for (int j=1;j<=n;j++){
			dp[i]=max(dp[i],dp[j]&a[i]);
		}
	}
	cout<< dp[m];

return 0;
}

