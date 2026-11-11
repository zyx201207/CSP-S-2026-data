#include<bits/stdc++.h>
using namespace std;
long long n,m,b,c;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		c=max(c,a[i]);
	}
	if(m==1)
	{
		cout<<c;
		return 0;
	}
	if(m==2)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				b=max(b,a[i]&a[j]);
			}
		}
	}
	if(m==3)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					b=max(b,a[i]&a[j]&a[k]);
				}
			}
		}
	}
	cout<<b;
}
