#include<bits/stdc++.h>
using namespace std;
namespace Ganlai
{
#define int long long
	const int N=2e5+1,INF=9e18;
	int T,n,k,ans;
	vector<int> edges[N];
	inline void addedge(const int &u,const int &v)
	{
		edges[u].push_back(v),
		edges[v].push_back(u);
	}
	vector<int> choose;
	inline void check(const int &p,bitset<N> &vis)
	{
		vis[p]=true;
		for(const int &i:edges[p])
			if(!vis[i]&&*lower_bound(choose.begin(),choose.end(),i)==i)
				check(i,vis);
	}
	inline void dfs(const int &p)
	{
		if(p==n+1)
		{
			bitset<N> vis;
			int cnt=0;
			for(const int &i:choose)
				if(!vis[i])
					check(i,vis),++cnt;
//			printf("%lld\n",cnt);
			if(cnt!=2)
				return;
//			puts("---");
			queue<int> q;
			vector<int> dist(n+1,INF);
			for(const int &i:choose)
				q.push(i),dist[i]=0;
			int Ans=0;
			while(!q.empty())
			{
				const int p=q.front();
				q.pop();
				Ans=max(Ans,dist[p]);
				for(const int &i:edges[p])
					if(dist[i]>dist[p]+1)
						dist[i]=dist[p]+1,
						q.push(i);
			}
			ans=min(ans,Ans);
			return;
		}
		if(p+k-choose.size()<=n)
			dfs(p+1);
		if(choose.size()<k)
		{
			choose.push_back(p);
			dfs(p+1);
			choose.pop_back();
		}
	}
	void main()
	{
		scanf("%*d%lld",&T);
		while(T--)
		{
			scanf("%lld%lld",&n,&k);
			for(int i=1;i<=n;++i)
				edges[i].clear();
			for(int i=1;i<n;++i)
			{
				int x,y;
				scanf("%lld%lld",&x,&y);
				addedge(x,y);
			}
			ans=INF;
			dfs(1);
			printf("%lld\n",ans);
		}
	}
#undef int
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	Ganlai::main();
	return 0;
}

