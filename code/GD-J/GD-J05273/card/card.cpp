#include<bits/stdc++.h>
using namespace std;
stack<int> sta;
int a[500001];
int cnt[300002];
int ans[300001];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]==0)
			{
				sta.push(a[j]);
				cnt[a[j]]=1;
			}
			else
			{
				while(sta.top()!=a[j])
				{
					cnt[sta.top()]=0;
					sta.pop();
				}
				
			}
		}
		for(int o=1;o<=m;o++)
		{
			if(cnt[o])
			{
				ans[o]++;
			}
		}
		for(int o=1;o<=m;o++)
		{
			cnt[o]=0;
		}
		while(!sta.empty())
		{
			sta.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
