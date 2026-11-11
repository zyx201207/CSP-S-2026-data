#include<bits/stdc++.h>
using namespace std;
struct abc{
	int u;
	int dx;
};
int d,q,C;
long long w[500005];
vector <abc> g[500005];
vector <int> ro[500005];
vector <int> gr[600];
long long t[600][300005];
int k[1000];
bool f[600];
long long anst=0;
long long dfs(int x,int y,long long ans,int bh)
{
	//cout<<ans<<endl;
	if(x==y)
	{
		ans+=t[x][bh];
		//cout<<x<<' '<<bh<<' '<<t[x][bh]<<endl;
		if(ans<anst||anst==-1)
		{
			anst=ans;
		}
		return ans;
	}
	int i;
	for(i=0;i<g[x].size();i++)
	{
		int dtx=g[x][i].dx,dx=g[x][i].u;
		if(!f[dx])
		{
			f[dx]=1;
			if(bh==dtx)
			{
				dfs(dx,y,ans,dtx);
			}
			else
			{
				//cout<<bh<<' '<<x<<' '<<dtx<<' '<<t[x][dtx]<<endl;
				dfs(dx,y,ans+t[x][bh]+t[x][dtx],dtx);
			}
			f[dx]=0;
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);//C测试点编号,n地铁线路数,m地铁站数,d每个地铁站最多被几条线路经过,q出行计划数 
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);//地铁口到站厅需要的时间 
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);//第i条路线经过的地铁站数 
		for(j=1;j<=k[i];j++)
		{	
			abc xs,ys;
			int xm,ym;
			scanf("%d%lld",&xm,&ym);//u经过的第i个地铁站,t站厅到站台的时间
			t[xm][i]=ym;
			ro[i].push_back(xm);
			gr[xm].push_back(i);
			if(j-1>0)
			{
				int y=ro[i].size()-2;
				xs.u=ro[i][y];
				xs.dx=i;
				ys.u=xm;
				ys.dx=i;
				g[xm].push_back(xs);
				g[ro[i][y]].push_back(ys);
			}
			//cout<<xm<<' '<<i<<endl;
		}
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=0;j<gr[i].size();j++)
		{
			cout<<gr[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int ii=1;ii<=q;ii++)
	{
		anst=-1;
		memset(f,0,sizeof(f));
		int xr,yr;
		scanf("%d%d",&xr,&yr);//起点,终点
		f[xr]=1;
		for(i=0;i<gr[xr].size();i++)
		{
			long long t1=w[xr]+w[yr]+t[xr][gr[xr][i]];
			//cout<<w[xr]<<' '<<w[yr]<<' '<<t[xr][gr[xr][i]]<<' '<<t1<<endl;
			dfs(xr,yr,t1,gr[xr][i]);
		}
		printf("%lld\n",anst);
	}
	return 0;
}
