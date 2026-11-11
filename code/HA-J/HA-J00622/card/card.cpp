#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[500000+10],ji[300000+10],v[300000+10],ji2[300000+10];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=0;k<n;k++)
	{
		long long zhen=k+1;
		for(int i=k+1;i<=n;i++)
		{
			v[a[i]]++;
			if(v[a[i]]==2)
			{
				zhen=i;
				for(int j=1;j<=m;j++)
				{
					v[i]=0;
				}
				v[a[i]]=1;
			}
		}
		for(int i=zhen;i<=n;i++)
		{
			ji2[a[i]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(ji2[j]!=0)
			{
				ji[j]++;
			}
			ji2[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ji[i]<<" ";	
	}
	return 0;
}
