#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long pos=1;
		for(long long j=i;j<=n;j++)
		{
			long long t=a[j],f=-1;
			for(long long k=1;k<=pos-1;k++)
			{
				if(b[k]==t)
				{
					f=k;
					break;
				}
			}
			if(f!=-1)
			{
				pos=f;
			}
			b[pos]=a[j];
			pos++;
		}
		for(long long j=1;j<=pos-1;j++)
		{
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
