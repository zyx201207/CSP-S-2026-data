#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[500005],s,x;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			for(int k = 0;k<x;k++)
			{
				if(c[k]==a[j])
				{
					x=k;
				}
			}
			c[x]=a[j];
			x++; 
		}
		for(int j = 0;j<x;j++)
		{
			b[c[j]]++;
			c[j]=0;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	} 
	return 0;
}
//Àî¼Î¾þ GD-J03853
