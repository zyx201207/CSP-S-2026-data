#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt[500005];
int jc()
{
	for(int i=1;i<n;i++)
	{
		if(a[i+1]<a[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=0;
	if(jc())
	{
		for(int i=1;i<=n;i++)
		{
			cnt[a[i]]=i;
		}
	}else
	{
		for(int x=1;x<=n;x++)
		{
			for(int i=x;i<=n;i++)
			{
				for(int j=1;j<=l;j++)
				{
					if(b[j]==a[i])
					{
						for(int z=j;z<=l;z++)
						{
							b[z]=0;
						}
						l=j-1;
					}
					
				}
				b[++l]=a[i];
			}
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=l;j++)
				{
					if(b[j]==i)
					{
						cnt[i]++;
						break;
					}
				}
			}
			for(int i=1;i<=l;i++)
			{
				b[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}			
