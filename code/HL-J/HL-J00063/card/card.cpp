#include<bits/stdc++.h>
using namespace std;
long long a[400000],b[400000],c[400000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i];
		}
		for(int j=1;j<i;j++)
		{
			b[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			for(int l=i;l<=j;l++)
			{
				if(b[l]==b[j]) 
				{
					for(int k=l;k<=j-1;k++)
					{
						b[k]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(b[j]!=0)
			{
				c[b[j]]++;
			}
		} 
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
