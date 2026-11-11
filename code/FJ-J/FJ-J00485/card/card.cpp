#include <bits/stdc++.h>
using namespace std;
int n,m,a[500002],b[300002],f[300002],top=1;
bool find(int x)
{
	for(int i=1;i<=top;i++)
	{
		if (b[i]==x)
		{
			return 1;
		}
	}
	return 0;
}
int finds(int x1)
{
	for(int i=1;i<=top;i++)
	{
		if (b[i]==x1)
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
		top=1;
		for(int r=1;r<=m;r++)
		{
			b[r]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(!find(a[j]))
			{
				b[top]=a[j];
				top++;
			}
			else
			{
				top=finds(a[j])+1;
			}
		}
		for(int k=1;k<=top;k++)
		{
			f[b[k]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<' ';
	}
	return 0;
}