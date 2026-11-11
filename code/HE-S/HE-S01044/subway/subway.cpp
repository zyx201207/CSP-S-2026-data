#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=505;
vector<pair<int,int> > vt[M];
vector<int> st[N];
//vt[i]表示i地铁站走到第first个线路的站台的花费为second 
//st[i]表示i号线路经过那些站 
int c,n,m,d,q;
int a[M],f[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				f[i][j]=1e18;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%lld%lld",&x,&y);
			vt[x].push_back(make_pair(i,y));
			st[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<st[i].size();j++)
		{
			int u=st[i][j],w0=0;
			for(int k=0;k<vt[u].size();k++)
				if(vt[u][k].first==i)
				{
					w0=vt[u][k].second;
					break;
				}
			for(int k=0;k<vt[u].size();k++)
			{
				int p=vt[u][k].first;
				if(p==k)
					continue;
				f[i][p]=min(f[i][p],w0+vt[u][k].second);
				f[p][i]=f[i][p];
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j && j!=k && i!=k)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=1e18;
		for(int i=0;i<vt[x].size();i++)
		{
			int u=vt[x][i].first,w1=vt[x][i].second;
			for(int j=0;j<vt[y].size();j++)
			{
				int v=vt[y][j].first,w2=vt[y][j].second;
				ans=min(ans,w1+f[u][v]+w2);
			}
		}
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
