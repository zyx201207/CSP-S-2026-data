//T4
#include <bits/stdc++.h>
using namespace std;
//评测机保佑O(n^2)过2e5，难度吓哭了
//难道......我......终究......还是......逃不过......AFO......的......命运......吗......
int n,m,a[500001],now[500001],ans[500001];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		int cur=0;
		unordered_map <int,int> mp;
		for(int j=i;j<=n;++j)
		{
			if(!mp[a[j]])
			{
				mp[a[j]]=++cur;
				now[cur]=a[j];
			}
			else
			{
				for(int k=mp[a[j]]+1;k<=cur;++k)
				{
					mp[now[k]]=0;
				}
				cur=mp[a[j]];
			}
		}
		for(auto i:mp)
		{
			if(i.second)
			{
				ans[i.first]++;
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
