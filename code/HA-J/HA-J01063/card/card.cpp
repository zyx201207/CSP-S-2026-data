#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[300010];
long long b[5010][3010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int h=1;h<=n;h++)
	{
		for(int i=h;i<=n;i++)
		{
			b[i][h]=a[i];
			for(int j=i-1;j>=1;j--)
			{
				if(b[i][h]==b[j][h])
				{
					for(int k=j;k<i;k++)
					{
						b[k][h]=0;
					}
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j][i]!=0)
			{
				c[b[j][i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
