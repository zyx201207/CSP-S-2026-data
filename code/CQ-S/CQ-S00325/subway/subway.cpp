#include<bits/stdc++.h>
using namespace std;
#define int long long
struct data
{
	int id,dis;
	friend bool operator <(data a,data b)
	{
		return a.dis>b.dis;
	}
};

int c,n,m,d,q;
int p[550009];//站厅到门口的用时
vector<int>g[550009],w[550009]; 
int a[550009],t[550009];
int xr,yr;
bool done[550009];
int dist[5009][5009];
int disdot[550009];
//m+1~m+n表示线路节点 

void DIJ(int root,bool jo)
{
	memset(disdot,0x3f,sizeof(disdot));
	dist[root-m][root-m]=0;
	disdot[root]=0;
	priority_queue<data>q;
	q.push({root,0});
	
	while(!q.empty())
	{
		int u=q.top().id;
		q.pop();
		if(done[u]==jo)continue;
		done[u]=jo;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			int c=w[u][i];
			if(disdot[u]+c<disdot[v])
			{
				disdot[v]=disdot[u]+c;
				q.push({v,disdot[v]});
			}
		}
	}
	
	for(int i=m+1;i<=m+n;i++)
	{
		dist[root-m][i-m]=disdot[i];
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&p[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%lld%lld",&a[j],&t[j]);
			g[a[j]].push_back(m+i);
			g[m+i].push_back(a[j]);
			w[a[j]].push_back(t[j]);
			w[m+i].push_back(t[j]);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		DIJ(m+i,i&1);
	}
	
	for(int i=1;i<=q;i++)
	{
		int ans=10000000000000000;
		
		scanf("%lld%lld",&xr,&yr);
		
		for(int j=0;j<g[xr].size();j++)
		{
			for(int k=0;k<g[yr].size();k++)
			{
				ans=min(ans,dist[g[xr][j]-m][g[yr][k]-m]+w[xr][j]+w[yr][k]+p[xr]+p[yr]);
			}
		}
		printf("%lld",ans);
		printf("\n");
	}
	
	return 0;
}
