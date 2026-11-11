#include<bits/stdc++.h>
using namespace std;
int n,m,a[200200],ans[100100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k[200200];
		for(int j=i;j<=n;j++)
		{
			k[j]=a[j];
			{
				for(int z=j-1;z>=i;z--)
				{
					if(k[j]==k[z])
					{
						for(int o=z;o<j;o++)
						  k[o]=-1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(k[j]>0)
			  ans[k[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}