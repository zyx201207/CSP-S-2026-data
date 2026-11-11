#include<bits/stdc++.h>
using namespace std;
int n,m,pz[5005],ans[3005];
bool ds[3005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>pz[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			ds[k]=0;
		}
		for(int j=i+1;j<=n;j++)
		{
			if(ds[pz[j]])
			{
				for(int k=1;k<=m;k++)
				{
					ds[k]=0;
				}
			}
			ds[pz[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=ds[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
