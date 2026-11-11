#include<bits/stdc++.h>
using namespace std;
int c[300009],n,a[500009],b[500009],x[300009],m;
bool c2[300009];
int dang;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(!c2[a[j]])
			{
				c2[a[j]]=1;
				b[j]=a[j];
				c[a[j]]=j;
			}
			else
			{
				for(int k=j;k>=c[a[j]];k--)
				{
					c2[b[k]]=0;
					b[k]=0;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(c2[j])
			{
				x[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<x[i]<<" ";
	}
	return 0;
}
