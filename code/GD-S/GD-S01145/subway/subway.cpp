#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10,N=510;
bool Mst;
int c,n,m,d,q;
int w[M];

int tot;
int head[M];
struct rail{
	int nex;
	int id;
	int ti;
}e[M];

void add(int i,int id,int ti)
{
	tot++;
	e[tot].nex=head[i];
	e[tot].id=id;
	e[tot].ti=ti;
	head[i]=tot;
}

int rid[M],rti[M],len;

int dis[N][N];
bool Med;
signed main()
{
//	cerr<<(&Med-&Mst)/1048576.0<<"\n";
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			int a,t;
			cin>>a>>t;
			add(a,i,t);
		}
	}
	//input
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		len=0;
		for(int j=head[i];j;j=e[j].nex)
		{
			len++,rid[len]=e[j].id,rti[len]=e[j].ti;
		}
		for(int j=1;j<=len;j++)
		{
			for(int k=1;k<=len;k++)
			{
				if(j==k) continue;
				int x=rid[j],y=rid[k],z=rti[j]+rti[k];
				dis[x][y]=min(dis[x][y],z);
			}
		}
	}
	//add edge
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	//min dis
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int j=head[x];j;j=e[j].nex)
		{
			for(int k=head[y];k;k=e[k].nex)
			{
				int x=e[j].id,y=e[k].id,z=e[k].ti+e[j].ti;
				int sum=z+dis[x][y];
				ans=min(ans,sum);
			}
		}
		//x!=y
		ans=ans+w[x]+w[y];
		cout<<ans<<endl;
	}
	//query
}
/*
subway
step1:存过i的铁路，md^2加边
step2:n^3最短路
step3:qd^2查询

fc subway.out subway6.ans -Bb

*/
