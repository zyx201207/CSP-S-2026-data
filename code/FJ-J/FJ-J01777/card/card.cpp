#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int aa[m+1];
	int d[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			for(int f=i;f<=j;f++)
			{
				if(a[j]==d[f])
				{
					for(int g=f;g<=j;g++)d[g]=0;
				}
			}
		}
		for(int y=i;y<=n;y++)if(d[y]!=0)
		{
			for(int r=1;r<=m;r++)
			{
				if(d[y]==a[r])aa[r]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<aa[r]<<" ";
	return 0;
}
