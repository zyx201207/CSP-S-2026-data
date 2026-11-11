#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],dp[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		b[i]=a[i]+b[i-1];
	dp[1]=1;
	int l=1;
	for(int i=2;i<=n;i++)
	 {
		 dp[i]=dp[i-1];
		 while(b[i-1]-b[l-1]+m<(i-l)*a[i])
			l++;
		 dp[i]=max(dp[i],i-l+1);
	 }
	 cout<<dp[n];
	return 0;
}
