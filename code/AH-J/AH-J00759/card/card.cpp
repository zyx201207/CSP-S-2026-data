#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans[30003],c[30003],v[30003];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<n;k++)
			{
				if(v[k]==c[j])
				{
					for(int x=k;x<j;x++)
					{
						v[x]=0;
					}
					break; 
				}
			}
			v[j]=c[j];
		}
		for(int i=1;i<=n;i++)
		{
			ans[v[i]]++;
			v[i]=0;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	
	return 0;
}
