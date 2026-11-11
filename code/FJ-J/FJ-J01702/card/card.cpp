#include<iostream>
using namespace std;
int a[10000005],b[100005],c[100005],d[100005];
int main()
{
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++ )
	{
		for(int j=i;j<=n;j++) 
		{
			if(c[a[j]]==1)
			{
				for(int v=d[a[j]];v<=j;v++)
				{
					c[v]=0;
				}
			}
			c[a[j]]=1;
			d[a[j]]=j;
		}
		for(int p=1;p<=m;p++)
		{
			b[p]+=c[p];
			c[p]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
