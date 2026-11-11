#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],sum[1000005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j+i-1<=n;j++)
		{
			int l=j,r=j+i-1;
			int c=a[r]*i-(sum[r]-sum[l-1]);
			if(c<=m)
			{
				ans=i;
				break;
			}
		}
		if(ans!=i)
			break;
	}
	cout<<ans;
	return 0;
}
