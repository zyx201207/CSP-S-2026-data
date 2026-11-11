#include <iostream>
using namespace std;
long long a[500005],b[500005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int g=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x=1;
			for(int k=j+1;k<=n;k++)
			{
				if(a[k]==a[j])
				{
					for(int l=k+1;l<=n;l++)
					{
						a[l]=0;
					}
					x=0;
					g=k+1;
				}
				if(x==1)
				{
				    a[g+1]=a[j];
				    g+=1;
				}
			}
		}
		for(int s=1;s<=m;s++)
		{
			for(int d=1;d<=g;d++)
			{
				if(b[s]==a[d])
				{
				    c[b[s]]++;
			    }
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
		{
			cout<<c[i]<<" ";
		}
	}
	return 0;
}
