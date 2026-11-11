#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1000005];
int n,k;
int qg[100005];
int gs,jl,ans;
int zj[100005];
void bfs(int p,int fa,int sf,int zh)
{
	zj[p]=zh;
	if (qg[p]==1)
	{
		if (sf==1)
		{
			zh=0;
		}
		else
		{
			sf=1;
			gs=gs+1;
			zh=0;
		}
		zj[p]=0;
	} 
	else
	{
		sf=0;
	}
	for (int i=0;i<vec[p].size();i++)
	{
		if (vec[p][i]!=fa)
		{
			bfs(vec[p][i],p,sf,zh+1);
			zj[p]=min(zj[p],zj[vec[p][i]]+1);
		}
	}
	jl=max(jl,zj[p]);
}
void dfs(int p,int yq)
{
	if (p==n+1)
	{
		if (yq<k)
		{
			return;
		}
		gs=0;
		jl=0;
		bfs(1,0,0,100000000);
		if (gs<=2)
		{
			ans=min(ans,jl);
		}
		return;
	}
	if (yq<k)
	{
		qg[p]=1;
		dfs(p+1,yq+1);
	}
	qg[p]=0;
	dfs(p+1,yq);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for (int j=1;j<=n;j++)
		{
			vec[j].clear(); 
		}
		for (int j=1;j<n;j++)
		{
			int u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		ans=1000000000;
		dfs(1,0);
		cout<<ans<<"\n";
	}
}
