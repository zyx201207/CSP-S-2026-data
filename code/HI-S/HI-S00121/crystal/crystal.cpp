#include<bits/stdc++.h>
using namespace std;
long long n,m,b,c=0,d;
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
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n-i;j++)
		{
			if(a[j]>=a[j+1])
			{
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		c=c+a[i];
		if(i*a[i+1]-c==m)
		{
			d=i+1;
		}
	}
	cout<<d;
	return 0;
 } 
