#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
struct Node{
	ll v,w;
};
struct str{
	ll id,t;
};
ll c,n,m,d,q,a[N],ans,k[N],g[505][505],l[505][505],a1[N][21];
vector<Node> e[N];
vector<str> b[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			ll x,y;
			cin>>x>>y;
			b[x].push_back({i,y});
			if(b[x].size()>1)
			{
				for(auto it : b[x])
				{
					if(it.id!=i)
					{
						g[i][it.id]=g[it.id][i]=min(g[i][it.id],it.t+y);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(g[i][j]!=1e18)
			{
				e[i].push_back({j,g[i][j]});
				e[j].push_back({i,g[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			l[i][j]=g[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					l[i][j]=0;
					continue;
				}
				l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
			}
		}
	}
	while(q--)
	{
		ll s,t;
		cin>>s>>t;
		ll ans=1e18;
		for(auto i : b[s])
		{
			for(auto j : b[t])
			{
				ans=min(ans,l[i.id][j.id]+a[s]+a[t]+i.t+j.t);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
