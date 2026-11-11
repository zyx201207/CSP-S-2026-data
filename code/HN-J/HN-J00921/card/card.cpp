#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int vis[300005];
int viv[300005];
int ans[300005];
int dis[500005];
int di[500005];
stack<int>op;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(n<=5000 and m<=3000)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j<=n;++j)
			{
				if(vis[a[j]])
				{
					while(vis[a[j]])
					{
						vis[op.top()]--;
						op.pop();
					}
				}
				vis[a[j]]++;
				op.push(a[j]);
			}
			while(!op.empty())
			{
				ans[op.top()]++;
				vis[op.top()]--;
				op.pop();
			}
		}
		for(int i=1;i<m;++i)
		{
			cout<<ans[i]<<' ';
		}
		cout<<ans[m];
		return 0;
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			dis[i]=i;
		}
		for(int i=1;i<=n;++i)
		{
			dis[viv[a[i]]]=i;
			viv[a[i]]=i;
		}
		for(int i=1;i<=n;++i)
		{
			int p=i;
			di[a[p]]=1;
			ans[a[p]]++;
			while(p<=n)
			{
				while(p!=dis[p])
				{
					p=dis[p];
				}
				p++;
				if(!di[a[p]])
				{
					di[a[p]]=1;
					ans[a[p]]++;
				}
			}
			p=i;
			di[a[p]]=0;
			while(p<=n)
			{
				while(p!=dis[p])
				{
					p=dis[p];
				}
				p++;
				di[a[p]]=0;
			}
		}
		for(int i=1;i<m;++i)
		{
			cout<<ans[i]<<' ';
		}
		cout<<ans[m];
	}
	return 0;
}
//3 1 2 1 3 2 3 1 2 1
