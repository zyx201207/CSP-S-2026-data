#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,ts;
int a[500005];
bool f[300005];
int sf[300005],dz[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]<=a[i]) ts++;
		maxn=max(maxn,a[i]);
	}
	if(ts==n)
	{
		for(int i=1;i<=m;i++)
			cout<<i<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=1;
				dz[a[j]]=j;
			}
			else
			{
				for(int k=dz[a[j]]+1;k<j;k++)
				{
					f[a[k]]=0;
				}
				dz[a[j]]=j;
			}
		}
		for(int j=1;j<=maxn;j++)
		{
			if(f[j]==1) sf[j]++;
			f[j]=0;
			dz[j]=0;
		}
	}
	for(int i=1;i<=maxn;i++) cout<<sf[i]<<' ';
	return 0;
}
