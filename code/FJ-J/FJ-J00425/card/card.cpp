#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int cnt[300005];
int sum[300005];
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
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
		}
		for(int j=1;j<=m;j++)
		{
			cnt[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			cnt[b[j]]++;
			if(cnt[b[j]]>1)
			{
				int z=j-1;
				while(true)
				{
					if(b[z]!=b[j])
					{
						b[z]=0;
						cnt[b[z]]--;
					}
					else
					{
						b[z]=0;
						cnt[b[z]]--;
						break;
					}
					z--;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]!=0) sum[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
