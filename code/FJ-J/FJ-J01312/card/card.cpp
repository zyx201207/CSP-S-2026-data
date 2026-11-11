#include<bits/stdc++.h>
using namespace std;
int a[500001];
int ans[300001];
int p[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			p[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]]!=0)
			{
				for(int k=p[a[j]]+1;k<j;k++)
				{
					if(a[k]!=a[j])
						p[a[k]]=0;
				}
			}
			else
			{
				p[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(p[j]!=0)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
