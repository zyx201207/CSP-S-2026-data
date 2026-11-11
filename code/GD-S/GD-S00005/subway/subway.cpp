#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[700000];
int num[700000];
vector<int> a[700000],t[700000];
struct A
{
	int id,w;
};
vector<A> z[700000];
int f[555][555];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int fw,n,m,d,Q;
	scanf("%lld%lld%lld%lld%lld",&fw,&n,&m,&d,&Q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=num[i];j++)
		{
			int x,v;
			scanf("%lld%lld",&x,&v);
			a[i].push_back(x);
			t[i].push_back(v);
			z[x].push_back({i,j});
		}
	}
	for(int i=1;i<=m;i++)
	{
//		cout<<z[i].size()<<endl;
		for(int j=0;j<1ll*z[i].size();j++)
		{
			for(int k=0;k<1ll*z[i].size();k++)
			{
				if(j==k) continue;
				int x=z[i][j].id,y=z[i][k].id;
//				cout<<i<<" "<<x<<" "<<y<<" "<<t[x][z[i][j].w]+t[y][z[i][k].w]<<"!!!"<<endl;
				f[x][y]=min(f[x][y],t[x][z[i][j].w]+t[y][z[i][k].w]);
				f[y][x]=min(f[y][x],t[x][z[i][j].w]+t[y][z[i][k].w]);
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
	for(int i=1;i<=Q;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=1e18;
		for(int j=0;j<1ll*z[x].size();j++)
		{
			for(int k=0;k<1ll*z[y].size();k++)
			{
				ans=min(ans,f[z[x][j].id][z[y][k].id]+t[z[x][j].id][z[x][j].w]+t[z[y][k].id][z[y][k].w]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}
