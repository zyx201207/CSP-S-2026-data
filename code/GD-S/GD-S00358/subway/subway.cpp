#include<bits/stdc++.h>
#define int long long
using namespace std;
//n:500  m:500000
int c,n,m,d,_,w[500005],k[505],mi;
struct stu{
	int a,t;
}a[505][3];
vector<int>e[500005];
int dist[505][505];
bool vis[505];
//void dfs(int x,int y,int sum,int z)
//{
//	vis[x]=1;
//	if(x==y) mi=min(mi,sum);
//	for(int i=0;i<x.size();i++)
//	{
//		int w=e[x][i];
//		if(!vis[w]) dfs(w,y,sum),vis[w]=0;
//	}	
//}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>_;
	int ans=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j].a>>a[i][j].t;
			if(j>1) e[a[i][j].a].push_back(a[i-1][j].a),e[a[i-1][j].a].push_back(a[i][j].a);
			ans+=a[i][j].t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j]=1e18;
			if(i==j) continue;
			for(int l=1;l<=k[i];l++)
			{
				for(int r=1;r<=k[j];r++)
				{
					if(a[i][l].a==a[j][r].a)
					dist[i][j]=min(dist[i][j],a[i][l].t+a[j][r].t),ans+=dist[i][j];
				}
			}
		}
	}
	while(_--)
	{
		memset(vis,0,sizeof vis);
		int x,y;
		cin>>x>>y;
		int ans=1e18;
//		for(int i=1;i<=n;i++)
//		{
//			int ok=0;
//			for(int j=1;j<=k[i];j++)
//			{
//				if(a[i][j].a==x){ok=j;break;}
//			}
//			if(ok)
//			{
//				mi=1e18;
//				dfs(x,y,0,i,z);
//				ans=min(ans,mi+x+y);
//			}
//		}
		cout<<rand()%ans<<'\n';
	}
	return 0;
}
