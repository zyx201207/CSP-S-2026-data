#include<bits/stdc++.h>
using namespace std;
int a[500100],flag[500100],f[500100];
int cnt[500100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int cnta=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(f[a[i]]==0)
		{
			f[a[i]]=1;
			cnta++;
		}
	}
	int l=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(flag[a[j]]==0)
			{
				flag[a[j]]=1;
			}
			else
			{
				for(int k=l;k<=j;k++)
				{
					flag[a[k]]=0;
					if(i>=2)
					{
						for(int o=l;o<=n;o++)
						{
							flag[a[o]]=0;
						}
					}
				}
				l=j+1;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(flag[a[j]]==1)
			{
				cnt[a[j]]++;
			} 
		}
	}
	for(int i=1;i<=cnta;i++)
	{
		if(cnt[i]!=0)
			cout<<cnt[i]<<" ";
	}
	return 0;
}
