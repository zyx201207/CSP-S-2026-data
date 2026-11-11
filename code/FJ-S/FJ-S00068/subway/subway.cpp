#include<bits/stdc++.h>
using namespace std;
//注意区分调试语句和运行语句

//awa
const long long inf=1e17;
int c,n,m,d,q;
long long w[500005];
int k[505];
struct node
{
	int li;
	long long t;
};
vector<node> a[500005];
long long dis[505][505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("test.out","w",stdout);
	//务必提交前取消freopen的注释
	
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
//		scanf("%lld",&w[i]);
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
//		scanf("%d",&k[i]);
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int sa;
			long long t;
//			scanf("%d%lld",&sa,&t);
			cin>>sa>>t;
			node g;
			g.li=i,g.t=t;
			a[sa].push_back(g);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=dis[j][i]=inf;
		} 
	}
	for(int i=1;i<=m;i++)
	{
		int len=a[i].size();
		for(int j=0;j<len;j++)
		{
			for(int k=j+1;k<len;k++)
			{
				long long ti=a[i][j].t+a[i][k].t;
				int x=a[i][j].li;
				int y=a[i][k].li;
				dis[x][y]=min(dis[x][y],ti);
				dis[y][x]=min(dis[y][x],ti);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	//调试ing 
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(dis[i][j]==inf)
//			{
//				cout<<"-1 ";
//			}
//			else
//			{
//				cout<<dis[i][j]<<" ";
//			}
//		}
//		cout<<"\n";
//	}
	
	//ed
	for(int p=1;p<=q;p++)
	{
		int x,y;
//		scanf("%d%d",&x,&y);
		cin>>x>>y;
		long long ans=w[x]+w[y];
		long long aw=inf;
		int lenx=a[x].size();
		int leny=a[y].size();
		for(int i=0;i<lenx;i++)
		{
			for(int j=0;j<leny;j++)
			{
				aw=min(aw,a[x][i].t+a[y][j].t+dis[a[x][i].li][a[y][j].li]);
			}
		}
		cout<<ans+aw<<'\n';
//		printf("%lld\n",ans+aw);
	}
	return 0;
}

