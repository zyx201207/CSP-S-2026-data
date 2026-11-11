#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000005],b[5000005],ans[3000005],cnt[3000005],id[3000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		memset(id,0,sizeof(id));
		for(int j=i;j<=n;j++)
		{
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++)
		{
			cnt[b[j]]++;
			if(cnt[b[j]]==2)
			{
				for(int k=id[b[j]];k<j;k++)
				{
					cnt[b[k]]--;
					b[k]=0;
				}
			}
			id[b[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(cnt[j]>=1)
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

