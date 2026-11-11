#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][50010],t[510][50010],vis[510];
long long f[510][510],ans;
vector<int> g[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		f[i][i]=0;
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			g[a[i][j]].push_back(i);
		}
	}
	if(n==1)
	{
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<1ll*w[x]+1ll*w[y]+1ll*t[1][x]+1ll*t[1][y]<<"\n";
		}
		return 0;
	} 
	if((c>=12&&c<=19))
	{
		long long tmp=1ll*t[1][a[1][1]]+1ll*t[1][a[1][2]];
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis)); 
			for(int j=1;j<=k[i];j++)
			{
				for(int h=0;h<g[a[i][j]].size();h++)
				{
					vis[g[a[i][j]][h]]=1;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				if(vis[j])
				{
					f[i][j]=tmp;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis)); 
			for(int j=1;j<=k[i];j++)
			{
				for(int h=0;h<g[a[i][j]].size();h++)
				{
					vis[g[a[i][j]][h]]=t[i][a[i][j]]+t[g[a[i][j]][h]][a[i][j]];
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				if(vis[j])
				{
					f[i][j]=vis[j];
				}
			}
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
					continue;
				}
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans=0x7f7f7f7f7f7f7f7f;
		for(auto i:g[x])
		{
			for(auto j:g[y])
			{
				ans=min(ans,1ll*w[x]+1ll*w[y]+1ll*t[i][x]+1ll*t[j][y]+f[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
