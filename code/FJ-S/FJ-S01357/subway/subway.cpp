#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace sol
{
	struct node
	{
		int v,w;
	};
	vector<node>g[500010];
	int w[500010];
	ll f[510][510];
	int main()
	{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		int c,n,m,d,q;
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int v,w;
				cin>>v>>w;
				g[v].push_back({i,w});
			}
		}
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++)f[i][i]=0;
//		int cnt1=0,cnt2=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<g[i].size();j++)
			{
				for(int k=j+1;k<g[i].size();k++)
				{
					int v1=g[i][j].v,w1=g[i][j].w;
					int v2=g[i][k].v,w2=g[i][k].w;
					f[v1][v2]=f[v2][v1]=min(f[v1][v2],1ll*w1+w2);
//					cnt2++;
				}
			}
//			if(g[i].size()>3)return 1;
//			if(g[i].size()>1)
//			{
//				cnt1++;
//				cerr<<g[i].size()<<'\n';
//			}
		}
//		cerr<<cnt1<<" "<<cnt2<<" "<<d<<" "<<m<<'\n';
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		while(q--)
		{
			int x,y;
			ll ans=1e18;
			cin>>x>>y;
			for(node e1:g[x])
				for(node e2:g[y])
					ans=min(ans,f[e1.v][e2.v]+e1.w+e2.w);
			cout<<ans+w[x]+w[y]<<'\n';
		}
		return 0;
	}
}
int main()
{
	sol::main();
	return 0;
}

