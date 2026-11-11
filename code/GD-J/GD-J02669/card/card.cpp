#include<bits/stdc++.h>
using namespace std;
long long n,m,pos[500001],a[500001],cnt[500001],ans[500001],fi[500001];
bool vis[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		memset(fi,0,sizeof(fi));
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]==0)
			{
				cnt[a[j]]++;
				fi[a[j]]=j;
			}
			else
			{
				for(int k=fi[a[j]];k<j;k++)
				{
					cnt[a[k]]=0;
				}
				cnt[a[j]]++;
				fi[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(cnt[j]!=0)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
