#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],zong[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int z=1;z<=n;z++)
	{
		cin>>a[z];
	}
	for(int o=1;o<=n;o++)
	{
		long long b[1000000];
		for(int z=o;z<=n;z++)
		{
			b[z]=a[z];
			for(int y=1;y<=z;y++)
			{
				if(b[y]==a[z])
				{
					for(int u=y;u<z;u++)
					{
						b[u]=0;
					}
					break;
				}
			}
		}
		for(int z=1;z<=n;z++)
		{
			if(b[z]!=0)
			{
				zong[b[z]]++;
			}
		}
	}
	for(int z=1;z<=m;z++)
	{
		cout<<zong[z]<<" ";
	}
	return 0;
}
