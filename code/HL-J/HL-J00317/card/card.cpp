#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int a[N],ans[N],sum[N];
int vis[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)vis[i]=0;
		for (int j=i;j<=n;j++)
		{
			for (int k=i;k<=j;k++)
			{
				if(a[k]==a[j])
				{
					if(!vis[i])
						vis[i]--;
					if(!vis[j])
						vis[j]++;
				}
			}
		}
		for (int j=i;j<=n;j++)sum[i]=vis[i]+vis[i-1];
		for (int j=i;j<=n;j++)if(sum[i]!=0&&a[i]==i)ans[i]++;
	}
	for (int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
