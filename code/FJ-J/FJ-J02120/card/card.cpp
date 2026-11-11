#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
long long a[500005];
long long b[300005];
long long c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	x=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[j]=a[j];
		}
		for(int j=x;j<=n;j++)
		{
			int p=0;
			for(int l=x;l<j;l++)
			{
				if(c[l]==c[j])
				{
					p=l;
					break;
				}
			}
			if(p!=0)
			{
				for(int l=p;l<j;l++)
				{
					c[l]=0;
				}
			}
		}
		for(int j=x;j<=n;j++)
		{
			b[c[j]]++;
		}
		x++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	
	
	return 0;
}
