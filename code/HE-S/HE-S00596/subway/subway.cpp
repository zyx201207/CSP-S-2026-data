#include<iostream>
#include<queue>
using namespace std;
const int maxn=505;
const int maxm=500005;
int c,n,m,d,qq;
int w[maxm];
struct nd{int l;int t;
};
nd zx[maxm][23];
int zxz[maxm];
int g[maxn][maxn];//i<j;
long long f[maxn][maxn];
inline void makebi(int a,int b,int t)
{
	if(a>b)swap(a,b);
	g[a][b]=min(g[a][b],t);
}
inline int getbi(int a,int b)
{
	if(a>b)swap(a,b);
	return g[a][b];
}
struct bian{int v;int w;
};
inline bool operator<(bian a,bian b)
{
	return a.w>b.w;
}
priority_queue<bian> q;
void dijstra(int u)
{
	
	//q.clean();
	f[u][u]=0;
	q.push(bian{u,0});
	while(!q.empty())
	{
		bian a=q.top();
		q.pop();
		if(a.w>f[u][a.v])continue;
		for(int i=1;i<=n;i++)
		{
			if(getbi(a.v,i)>=2000000000+1)continue;
			if(f[u][a.v]+getbi(a.v,i)<f[u][i])
			{
				f[u][i]=f[u][a.v]+getbi(a.v,i);
				q.push(bian{i,f[u][i]});
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",w+i);
		//cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d%d",&a,&t);
			//cin>>a>>t;
			zxz[a]++;
			zx[a][zxz[a]]=nd{i,t};
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]=2000000000+1;
			f[i][j]=1e18;
		}
	 } 
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=zxz[i];j++)
		{
			for(int h=1;h<j;h++)
			{
				makebi(zx[i][j].l,zx[i][h].l,zx[i][j].t+zx[i][h].t);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		dijstra(i);
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=zxz[i];j++)
		{
			cout<<zx[i][j].l<<'+'<<zx[i][j].t<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<g[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=1;i<=qq;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		long long res=1e18;
		for(int j=1;j<=zxz[l];j++)
		{
			for(int h=1;h<=zxz[r];h++)
			{
				res=min(res,f[zx[l][j].l][zx[r][h].l]+zx[l][j].t+zx[r][h].t);
			}
		}
		cout<<res+w[l]+w[r]<<endl;
	}
	return 0;
 } 
