#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
#define int unsigned long long
int c,n,m,d,q;
int w[M],k[N],dis[N][N];
int cur,a[M],t[M],v[N][N];
vector<int>g[M];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1,x;j<=k[i];++j)
		{
			++cur;
			cin>>x>>t[cur];
			a[cur]=i;
			g[x].push_back(cur);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	memset(v,0x3f,sizeof(v));
	for(int i=1;i<=n;++i)
	{
		dis[i][i]=0ll;
		v[i][i]=0ll;
	}
	for(int i=1;i<=m;++i)
	{
		for(int j:g[i])
		{
			for(int k:g[i])
			{
				if(j==k)continue;
				dis[a[j]][a[k]]=0ll;
				v[a[j]][a[k]]=min(v[a[j]][a[k]],t[j]+t[k]);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(dis[i][k]+dis[k][j]+v[i][k]+v[k][j]<dis[i][j]+v[i][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					v[i][j]=v[i][k]+v[k][j];
				}
			}
		}
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=n;++j)
//		{
//			cout<<dis[i][j]+v[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	int x,y,ans;
	while(q--)
	{
		cin>>x>>y;
		ans=LLONG_MAX;
		for(int i:g[x])
		{
			for(int j:g[y])
			{
				if(v[a[i]][a[j]]==t[i]+t[j])ans=min(ans,dis[a[i]][a[j]]+v[a[i]][a[j]]);
				else ans=min(ans,dis[a[i]][a[j]]+v[a[i]][a[j]]+t[i]+t[j]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
