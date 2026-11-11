#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[200005],b[200005],c[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			if(j>=i)
			{
				if(b[j-1]==0&&c[j-1]==0)
				{
					c[j]=a[j];
				}
				else
				{
				
					c[j]=max(c[j-1],(b[j-1]&a[j]));
					if(b[j-1]==0)
					{
						c[j]=max(c[j-1],a[j]);
					}
				} 
			}
		 } 
		for(long long j=1;j<=n;j++)
		{
			b[j]=c[j];
			c[j]=0;
		} 
	}
	cout<<b[n];
	
} 
 
