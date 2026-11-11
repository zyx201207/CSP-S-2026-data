#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long w[500005];
long long k[500005];
long long dis[505][505];
struct node
{
	long long v,w;
};
vector<node> p[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++ ) 
	{
		cin>>w[i];
	}
	for(int i = 1; i <= n; i++ )
	{
		for(int j = 1; j <= n; j++ )
		{
			dis[i][j] = 0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>k[i];
		for(int j = 1; j <= k[i]; j++ )
		{
			long long x,y;
			cin>>x>>y;
			p[x].push_back({i,y});
		}
		dis[i][i]=0;
	}
	for(int i = 1; i <= m; i++ )
	{
		for(int j = 0; j < p[i].size(); j++ )
		{
			for(int k = j+1; k < p[i].size(); k++ )
			{
				int x = min(p[i][j].v,p[i][k].v),y=max(p[i][j].v,p[i][k].v);
				dis[x][y] = min(dis[x][y],p[i][j].w+p[i][k].w);
			}
		}
	}

	for(int i = 1; i <= n; i++ )
	{
		for(int j = i+1; j <= n; j++ )
		{
			for(int k = 1; k <= n; k++ )
			{
				dis[i][j] = min(dis[i][j],dis[min(i,k)][max(i,k)]+dis[min(j,k)][max(j,k)]);
			}
		}
	}
//	for(int i = 1; i <= n; i++ )
//	{
//		for(int j = i; j <= n; j++ )
//		{
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i = 1; i <= n; i++ )
	{
		for(int j = 1; j < i; j++ )
		{
			dis[i][j] = dis[j][i];
		}
		
	}
	for(int i = 1; i <= q; i++ )
	{
		int x,y;
		cin>>x>>y;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(int j = 0; j < p[x].size(); j++ )
		{
			for(int k = 0; k < p[y].size(); k++ )
			{
				ans = min(ans,dis[p[x][j].v][p[y][k].v]+p[x][j].w+p[y][k].w);
//				cout<<p[x][j].v<<" "<<p[x][j].w<<" "<<p[y][k].v<<" "<<p[y][k].w<<endl;
			}
		}
//		cout<<ans<<endl;
		cout<<ans+w[x]+w[y]<<endl;
	}
}
