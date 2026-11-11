#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(long long i=1;i<=n;i++)
	cin>>a[i];
	for(long long i=n;i>=1;i--)
	{
		long long cnt=0,ans;
		for(long long j=1;j<=i;j++)
		{
			cnt+=a[i]-a[j];
			ans=j;
		}
		if(cnt==m)
		{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
