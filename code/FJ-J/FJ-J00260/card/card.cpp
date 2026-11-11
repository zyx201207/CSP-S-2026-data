#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],x,ii,z[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	int nn=n;
	while (nn--)
	{
		ii++;
		for (int i=ii;i<=n;i++)
		{
			for (int j=x;j>=1;j--)
			{
				if (a[i]==b[j])
				{
					x=j-1;
					break;
				}
			}
			x++;
			b[x]=a[i];
		}
		for (int i=1;i<=x;i++)
		{
			z[b[i]]++;		
		}
		x=0;	
	}
	for (int i=1;i<=m;i++)
	{
		cout<<z[i]<<" ";
	}
	return 0;
}
//4 3 1 2 1 3
