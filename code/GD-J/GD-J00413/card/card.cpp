#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int y=0;
		int b[500005]={};
		for(int j=i;j<=n;j++)
		{
			y++;
			b[y]=a[j];
			for(int k=1;k<=y-1;k++)
			{
				if(b[k]==b[y])
				{
					int sum=y-k;
					for(int o=k;o<=sum;o++)
					{
						b[o]=0;
					}
					b[k]=b[y];
					b[y]=0;
					y-=sum;
					break;
				}
			}
			
		}
		for(int j=1;j<=y;j++)
		{
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
} 
