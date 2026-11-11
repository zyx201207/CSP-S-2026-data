#include<bits/stdc++.h>
using namespace std;
int c,t;
#define int long long
namespace did
{
	int n,d,h[100005];
	vector<int> g[100005];
	bool b(int l,int r)
	{
		int dis[100005]={},cnt=0;
		for(int i=1;i<=n;i++) dis[i]=1e9;
		dis[l]=0;
		queue<pair<int,int> > q;q.push({l,0});
		while(!q.empty())
		{
			pair<int,int> u=q.front();q.pop();
			if(u.second!=dis[u.first]) continue;
			if(u.first==r) cnt++;
			if(cnt>=3) return 0;
			for(int v:g[u.first])
			{
				if(v>r) break;
				if(dis[v]<u.second+1) continue;
				dis[v]=u.second+1,q.push({v,dis[v]});
			}
		}
		return cnt==2;
	}
	void solve()
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(h[j]-h[i]>d) break;
				g[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(h[j]-h[j-1]>d) break;
				if(b(i,j)) ans++;
			}
		printf("%lld\n",ans);
	}
	signed main()
	{
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		cin>>c>>t;
		while(t--)solve();
		return 0;
	}
}
signed main()
{
	did::main();
	return 0;
}
/*
 ±º‰O(???),π¿∑÷??(20?) 
*/
