#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k[505],s[505][505];
struct Node{
	int c,t;
};
vector<Node>zt[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)s[i][j]=1e15;
		}
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;cin>>a>>t;
			zt[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto u:zt[i])
		{
			for(auto v:zt[i])
			{
				s[u.c][v.c]=min(s[u.c][v.c],u.t+v.t);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				s[j][k]=min(s[j][k],s[j][i]+s[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=1e15;cin>>x>>y;
		for(auto u:zt[x])
		{
			for(auto v:zt[y])
			{
				ans=min(s[u.c][v.c]+u.t+v.t,ans);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

