//Please let me go.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
		{x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
typedef pair<int,int> p;
const int N=507;
const int M=5e5+7;
const int W=27;
vector<p>way[N];
int c,n,m,d,q;
ll minn;
int w[M],k[N],op[M],v[M][W][2];
ll dis[N][N];
void Floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(k==i||k==j||i==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
}
void add(int u)
{
	int i,j,a,b;
	ll va,vb;
	for(i=1;i<=op[u];i++)
		for(j=1;j<=op[u];j++)
		{
			if(i==j)continue;
			a=v[u][i][0];b=v[u][j][0];
			if(!a||!b)continue;
			va=v[u][i][1];vb=v[u][j][1];
			way[a].push_back({b,va+vb});
			way[b].push_back({a,va+vb});
			dis[a][b]=dis[b][a]=min(dis[a][b],va+vb);
		}
}
ll query(int s,int r)
{
	int i,j,a,b;
	minn=1e19;
	for(i=1;i<=op[s];i++)
		for(j=1;j<=op[r];j++)
		{
			a=v[s][i][0];b=v[r][j][0];
			minn=min(minn,dis[a][b]+w[s]+w[r]+
				v[s][i][1]+v[r][j][1]);
		}
	return minn;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,a,t,s,r;
	memset(dis,0x3f,sizeof dis);
	c=read();n=read();m=read();d=read();q=read();
	for(i=1;i<=m;i++)
		w[i]=read();
	for(i=1;i<=n;i++)
	{
		k[i]=read();
		for(j=1;j<=k[i];j++)
		{
			a=read();t=read();
			v[a][++op[a]][0]=i;
			v[a][op[a]][1]=t;
		}
	}
	for(i=1;i<=m;i++)
		add(i);
	for(i=1;i<=n;i++)
		dis[i][i]=0;
	Floyd();
	while(q--)
	{
		s=read();r=read();
		printf("%lld\n",query(s,r));
	}
	return 0;
}
