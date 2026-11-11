#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct zt
{
	long long x,t;
};
vector <zt> a[500050];
long long b[500050];
long long lx[505][505];
long long ans=LLONG_MAX;
long long dfs(int x,int y)
{
	//cout<<x<<" "<<y<<" ";
	long long ans1=LLONG_MAX;
	if(x==y) return 0;
	if(lx[x][y]!=LLONG_MAX) return lx[x][y];
	for(int i=1;i<=n;i++)
	{
		if(lx[x][i]!=LLONG_MAX&&x!=i)
		{
			int zc=lx[x][i];
			lx[x][i]=LLONG_MAX;
			lx[i][x]=LLONG_MAX;
			long long dfs1=dfs(i,y);
			if(dfs1!=LONG_MAX) 
				ans1=min(dfs1+zc,ans1);
			lx[x][i]=zc;
			lx[i][x]=zc;
		}
	}
	//cout<<ans1<<"\n";
	return lx[x][y]=ans1;
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<505;i++)
	{
		for(int j=0;j<505;j++)
		{
			lx[i][j]=LLONG_MAX;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		zt s;
		int k;
		cin>>k;
		s.x=i;
		for(int j=1;j<=k;j++)
		{
			int aa;
			cin>>aa>>s.t;
			a[aa].push_back(s);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(unsigned long long j=0;j<a[i].size();j++)
		{
			for(unsigned long long k=0;k<a[i].size();k++)
			{
				lx[a[i][j].x][a[i][k].x]=min(lx[a[i][j].x][a[i][k].x],a[i][j].t+a[i][k].t);
				lx[a[i][k].x][a[i][j].x]=lx[a[i][j].x][a[i][k].x];
			}
		}
	}
	for(int w=0;w<q;w++)
	{
		int x,y;
		cin>>x>>y;
		//cout<<x<<" "<<y<<"\n";
		ans=LLONG_MAX;
		for(unsigned long long i=0;i<a[x].size();i++)
		{
			for(unsigned long long j=0;j<a[y].size();j++)
			{
				//cout<<a[x][i].x<<" "<<a[y][i].x<<lx[a[x][i].x][a[y][i].x]<<"\n";
				ans=min(ans,dfs(a[x][i].x,a[y][j].x)+b[x]+b[y]+a[x][i].t+a[y][j].t);
				//cout<<ans<<"\n";
				
			}
		}
		cout<<ans<<"\n"; 
	}
}
/*
0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
*/
