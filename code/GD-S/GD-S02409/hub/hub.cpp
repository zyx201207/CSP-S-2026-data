/*
显然是需要二分？树上连通块相关啊。
先搞个暴力，15 pts。 t*2^n*n。
对于 k=2 的情况，不是很会啊。
树上问题我们会从子树考虑，f[u][k][0/1] 表示，u 这棵子树，已经放了 k 个点，形成了
1/2 个连通块，最大最小距离是多少。求出来这个之后，预处理外部点的，可以得到答案。
这个东西可以 O(n) 预处理。
能不能转移呢。这个太困难了，算了。
放弃吧。写代码了。
*/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

using ll = long long ;
using ii = __int128;
using vl = vector<ll>;
using vi = vector<int>;

const int inf=1e9;

void solve()
{
	int n,k; cin>>n>>k;
	vector<vi> G(n+5);
	for(int i=1;i<n;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		G[u].pb(v);
		G[v].pb(u);
	}

	int ans=inf;
	for(int i=0;i<1<<n;i++)
	{
		int c=0;
		for(int j=0;j<n;j++) if(i>>j&1) c++;
		if(c!=k) continue ;

		int uni=0;
		vi dis(n+5,inf),vis(n+5);
		for(int j=0;j<n;j++)
		{
			if(!(i>>j&1)) continue ;
			if(!vis[j]) uni++;
			for(int v:G[j]) vis[v]=1;
			dis[j]=0;

			auto dfs=[&](auto dfs,int u,int f)->void
			{
				for(int v:G[u])
				{
					if(v==f||dis[v]<=dis[u]+1) continue ;
					dis[v]=dis[u]+1;
					dfs(dfs,v,u);
				}
			};dfs(dfs,j,-1);
		}

		int mx=0;
		for(int j=0;j<n;j++) mx=max(mx,dis[j]);
		if(uni<=2)
		{
			ans=min(ans,mx);
			// cerr<<i<<": "<<mx<<"\n";
			// if(mx==1)
			// {
			// 	cerr<<bitset<10>(i)<<":\n";
			// 	for(int j=0;j<n;j++) cerr<<dis[j]<<" \n"[j==n-1];
			// }
		}
	}
	cout<<ans<<"\n";
	// cerr<<ans<<"\n";
}

int main()
{
	freopen("hub3.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t; cin>>c>>t;
	while(t--) {solve();}
}