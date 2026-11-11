#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,p,k,ans=0;
long long w[N];
vector<int>g[N];
struct edge
{
	long long t;
	long long tong;
}sub[N];
long long dfs(int x,int y)
{
	int yy=y;
	ans+=w[x];
	ans+=sub[x].t;
	long long id=x;
	while(id==yy)
	{
		for(int i=1;i<=sub[x].tong;i++)
		{
			ans+=sub[i].t;
			id=i;
			ans=min(ans,dfs(id,yy));
		}	
	}
	ans+=w[y];
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int i=1;i<=k/2;i++)
		{
			long long u,v,tu,tv;
			cin>>u>>tu>>v>>tv;
			g[u].push_back(v);
			g[v].push_back(u);
			sub[u].t=tu;
			sub[v].t=tv;
			sub[u].tong++;
			sub[v].tong++;
		
	}
	for(int i=1;i<=p;i++)
	{
		long long x,y;
		cin>>x>>y;
		cout<<dfs(x,y)<<endl;
	}
	
}
