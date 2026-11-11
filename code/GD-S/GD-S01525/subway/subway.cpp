#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N=5e5+10,M=5e2+10,inf=1e18;
vector<PII>G[N];
int a[N],f[M][M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int op,m,n,d,T;
	scanf("%lld%lld%lld%lld%lld",&op,&m,&n,&d,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1,k;i<=m;i++)
	{
		scanf("%lld",&k);
		for(int j=1,x,w;j<=k;j++)
		{
			scanf("%lld%lld",&x,&w);
			G[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=f[j][i]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(auto I:G[i])
		{
			int x=I.first,w=I.second;
			for(auto J:G[i])
			{
				int y=J.first;
				if(y==x)
				{
					continue;
				}
				w+=J.second;
				f[x][y]=min(f[x][y],w);
				f[y][x]=min(f[y][x],w);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j==i)
			{
				continue;
			}
			for(int k=1;k<=m;k++)
			{
				if(k==i||k==j)
				{
					continue;
				}
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		f[i][i]=0;
	}
	while(T--)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		int ans=inf;
		for(auto i:G[l])
		{
			int x=i.first;
			for(auto j:G[r])
			{
				int y=j.first;
				int w=i.second+j.second;
				ans=min(ans,a[l]+f[x][y]+w+a[r]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
