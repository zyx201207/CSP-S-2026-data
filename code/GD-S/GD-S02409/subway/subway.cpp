/*
建出图之后跑最短路就好了，这里线路很少，估计要在上面做
Floyd。
处理出线路之间的全员最短路，因为这个 d 的限制，每个
点属于的线路很少。
直接枚举啊，400 * 1e5 = 4e7，直接过了？

具体地，需要先处理出站台之间的距离。
对于每一个点，枚举他所有儿子，然后松弛出距离。
对于新的图，跑一边 floyd。然后处理询问。
枚举哪个点合适，然后松弛。
时间复杂度 O(d^2 * \sum k + d^2 q)，可以过。2e8.
*/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

using ll = long long ;
using ii = __int128;
using vl = vector<ll>;
using vi = vector<int>;
using a2 = array<int,2>;

const ll inf=1e18;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	vi w(m+5);
	for(int i=1;i<=m;i++) cin>>w[i];

	vector<vector<a2>> G(m+5);
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t; cin>>a>>t;
			G[a].pb({i,t});
		}
	}

	// Floyd
	vector<vl> f(n+5,vl(n+5,inf));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int sz=G[i].size();
		for(int j=0;j<sz;j++)
		{
			for(int k=0;k<sz;k++)
			{
				int u=G[i][j][0],v=G[i][k][0];
				ll w1=G[i][j][1],w2=G[i][k][1];
				f[u][v]=min(f[u][v],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}

	while(q--)
	{
		int u,v; cin>>u>>v;
		ll ans=inf;
		for(a2 i:G[u])
		{
			for(a2 j:G[v])
			{
				int s=i[0],e=j[0],w1=i[1],w2=j[1];
				ll t=w1+f[s][e]+w2+w[u]+w[v];
				ans=min(ans,t);
			}
		}
		cout<<ans<<"\n";
	}
}
// g++ subway.cpp -o subway -std=c++14 -Wall -Wextra -O2 -Wshadow && .\subway && fc subway.out subway.ans