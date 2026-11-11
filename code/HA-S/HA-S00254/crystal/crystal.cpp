#include<bits/stdc++.h>
using namespace std;
long long q[500005][500005];
long long n=0,m=0;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=n;i>=1;i--)
	{
		for(long long l=i;l>=1;l--)
		{
			 q[l][i]=(a[i]-a[l])+q[l+1][i];
		}
	}
	long long ans=0;
	for(long long i=1;i<n;i++)
	{
		for(long long j=i;j<n;j++)
		{
			if(q[i][j]<=m)
			ans=max((abs(i-j)+1),ans);
		}
	}
	cout<<ans;
	return 0;
}
