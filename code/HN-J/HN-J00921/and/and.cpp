#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
vector<int>g[35];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		for(int j=30;j>=0;--j)
		{
			if(a[i]&(1<<j))
			{
				g[j].push_back(i);
			}
		}
	}
	int ans=0;
	for(int i=30;i>=0;--i)
	{
		if(g[i].size()>=m)
		{
			ans+=(1<<i);
			for(int j=0;j<i;++j)
			{
				g[j].clear();
			}
			for(auto e:g[i])
			{
				for(int j=i-1;j>=0;--j)
				{
					if(a[e]&(1<<j))
					{
						g[j].push_back(e);
					}
				}
			}
		}
		g[i].clear();
	}
	cout<<ans;
	return 0;
}

