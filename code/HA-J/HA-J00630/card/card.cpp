#include<bits/stdc++.h>
using namespace std;
long long n,m,n1=0,a[510000],b[510000],c[310000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		{
			if(n1==0)
			{
				n1+=1;
				b[n1]=a[i];
			}
			else
			{
				for(int j=1;j<=n1;j++)
				{
					if(a[i]==b[j])
					{
						for(int l=j+1;l<=n;l++)
						{
							b[l]=0;
						}
						n1=j;
						break;
					}
					if(j==n1)
					{
						n1+=1;
						b[n1]=a[i];
						break;
					}
				}
			}
		}
		for(int i=1;i<=n1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i]==j)
				{
					c[j]+=1;
				}
			}
		}
		n1=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				break;
			}
			b[i]==0;
		}
	}
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
