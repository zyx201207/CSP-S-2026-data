#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n = 0,sum = 0;
	long long m = 0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			sum+=abs(a[i]-a[j]);
		}
		b[i] = sum;
		sum = 0;
	}
	int k = 1,p = b[1];
	for(int i = 1;i<=n;i++)
	{
		if(p>b[i])
		{
			p = b[i];
			k = i;
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		if(m>=(a[k]-a[i])&&a[k]>=a[i])
		{
			m-=abs(a[i]-a[k]);
			ans++;
		}
		else
		{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
} 
