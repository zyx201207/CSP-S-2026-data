#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[500005],j=1,f[300005];
int find(int k)
{
	for(int z=1;z<=500005;z++)
	{
		if(vis[z]==k)
			return z;
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int q=1;q<=n;q++)
	{
		for(int i=1;i<=n;i++)
		{
			int k=i;
			if(find(k)!=0)
			{
				j=find(k)+1;
			}
			else
			{
				vis[j]=a[i];
				j++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			f[vis[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	cout<<'\n';
	return 0;
}
