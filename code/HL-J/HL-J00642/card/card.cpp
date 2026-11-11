#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500001],b[500001],temp[500001],ii;
ll have(ll x)
{
	for(int i=1;i<=n;i++)
	{
		if(temp[i]==x)
		{
			return i;
		}
	}
	return 0;
}
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
		for(int i=1;i<=n;i++)
		{
			temp[i]=0;
		}
		int ii=1;
		for(int j=i;j<=n;j++)
		{
			int h=have(a[j]);
			if(h!=0)
			{
				for(int k=h+1;k<=n;k++)
				{
					temp[k]=0;
				}
			}else
			{
				temp[ii]=a[j];
				ii++;
			}
		}
		for(int j=1;j<=ii;j++)
		{
			b[temp[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
