#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000006],c[1000006];
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
		int b[1000006];
		int x=a[i];
		b[x]++;
		if(b[x]>1)
		{
			for(int j=1;j<i;j++)
			{
				if(a[j]==x)
				{
					for(int k=j;k<i;k++)
					{
						int y=a[k];
						b[y]--;
					}
					break;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]>0)
			{
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
