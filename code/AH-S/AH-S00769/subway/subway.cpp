#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
struct node
{
	int v,val;
};
vector<node>g[M+N];//1~m号节点表示该站台的对应站厅, n+1~2n中的n+i号节点表示i号线路 (因为无需步行，所以同一条线路上的站台间相当于没有距离) 
int w[M];
int f[N][N];//两线路间距离 
int a[M];
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
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int val;
			cin>>a[j]>>val;
			g[a[j]].push_back({i+n,val});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int t=g[i][j].v-n;
			for(int l=0;l<g[i].size();l++)
			{
				int t2=g[i][l].v-n;
				if(t==t2) continue;
				f[t][t2]=f[t2][t]=g[i][j].val+g[i][l].val;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i][k]==INF) continue;
			for(int j=1;j<=n;j++)
			{
				if(f[i][k]==INF) continue;
				if(f[i][j]>f[i][k]+f[k][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=LLONG_MAX;
		for(int i=0;i<g[x].size();i++)
		{
			for(int j=0;j<g[y].size();j++)
			{
				int l1=g[x][i].v-n,l2=g[y][j].v-n;
				ans=min(ans,f[l1][l2]+g[x][i].val+g[y][j].val);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
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
