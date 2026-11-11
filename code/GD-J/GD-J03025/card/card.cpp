#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],d[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=0,c[i]=0;
		d[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i]=a[i];
		}
		for(int j=i;j<=n;j++)
		{
			if(b[d[j]]!=0)
			{
				int ans=0;
				for(int k=i;k<j;k++)
				{
					if(d[k]==d[j])
					{
						ans=1;
					}
					if(ans!=0)
					{
						b[d[k]]--;
						d[k]=0;
					}
				}
			}
			b[d[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			c[j]+=b[j];
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
