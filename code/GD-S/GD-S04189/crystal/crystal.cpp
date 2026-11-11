#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ans=0;
long long cha[500010];
long long sum[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cha[i]=abs(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+cha[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]<=m)
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	cout<<ans;
	return 0;	
} 
