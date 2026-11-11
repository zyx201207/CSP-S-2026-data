#include<bits/stdc++.h>
using namespace std;
int a[300009],b[500009],c[300009];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int x;
	for(int i=1;i<=n;i++)
	{
		x=i;
		for(int j=i;j<=n;j++)
		{
			for(int k=j-1;k>=x;k--)
			{
				if(b[j]==b[k])
				{
					x=j;
					break;
				}
			}
		}
		for(int j=x;j<=n;j++)
		{
			c[j]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[b[i]]+=c[i];
	}
	a[b[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
//10 3 3 1 2 1 3 2 3 1 2 1
//
/*

*/
