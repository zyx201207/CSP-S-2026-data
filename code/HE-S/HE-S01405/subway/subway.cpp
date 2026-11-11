#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k;
int u,v;
int g,t;
long long ans;
int dis[1008611];
vector<pair<int,int> > a[1008611];
void dfs(int u)
{
	if(u==v)
	{
		cout<<ans;
		return ;
	}
	for(auto y : a[u])
	{
		if(dis[u]+dis[y.first]>y.second)
		{
			ans+=dis[u]+y.second;
			dis[y.first]=dis[u]+y.second;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
		dis[i]=w;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int l=1;l<=2*k;l++)
		{
			cin>>g>>t;
			a[i].push_back({g,t});
			a[g].push_back({i,t});
		}
	}
	while(p--)
	{
		cin>>u>>v;
		dfs(u);
	}
	
	
	
	return 0;
}
