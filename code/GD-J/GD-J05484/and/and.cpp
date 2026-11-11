#include<iostream>
using namespace std;
int a[200005];
bool vis[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=30;i>=1;i--)
	{
		int shu=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])
			{
				continue;
			}
			if(((a[j]>>(i-1))&1)==1)
			{
				shu++;
			}
		}
		if(shu<m)
		{
			continue;
		}
		int zhi=2147483647;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])
			{
				continue;
			}
			if(((a[j]>>(i-1))&1)==0)
			{
				vis[j]=true;
			}
			else
			{
				zhi=zhi&a[j]; 
			}
		}
		if(shu==m)
		{
			cout<<zhi;
			return 0;
		}
	}
	int ji=0;
	int zhi=2147483647;
	for(int i=1;i<=n;i++)
	{
		if(ji==m)
		{
			cout<<zhi;
			return 0;
		}
		if(vis[i]) continue;
		ji++;
		zhi=zhi&a[i];
	}
}
