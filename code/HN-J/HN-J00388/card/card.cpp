#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500010];
	int tong[300010]={0};
	int tong2[300010]={0};
	int b[500010];
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		tong[300010]={0};
		for(int j=i;j<=n;j++)
		{
			if(tong[a[j]]==0)
			{
				tong[a[j]]++;
				b[j]=a[j];
			}
			else
			{
				for(int k=1;k<=n;k++)
				{
					if(b[k]==a[j])
					{
						x=k;
						break;
					}
				}
				for(int k=x;k<=j-1;k++)
				{
					tong[k]=0;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(tong[j]==1) tong2[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong2[i]<<" ";
	}
	return 0;
} 
