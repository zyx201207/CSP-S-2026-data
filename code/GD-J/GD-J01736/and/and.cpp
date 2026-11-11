#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,a[200100],b[200100];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=29;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if((ans&a[j])!=ans)
			{
				continue;
			}
			if((a[j]>>i)&1)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=1<<i;
		}
	}
	cout<<ans;
	return 0;
}
/*
Trick||Treat!
*/
