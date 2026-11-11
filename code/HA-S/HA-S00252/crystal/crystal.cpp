#include<bits/stdc++.h>
using namespace std;
long long a[10000005],b[10000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,k=0;
	cin>>n>>m;
	cin>>a[1];
	
	for(long long i=2;i<=n;i++)
	{
		cin>>a[i];
	
	}
	sort(a,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=i;j++)
	{
		if(b[i]-b[j]<=m)
		{
			if(i-j+1>k) k=i-j+1;
		}
	}
	}
	cout<<k;
	return 0;
}
