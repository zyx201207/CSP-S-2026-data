#include<bits/stdc++.h>
using namespace std;
long long int w[1010101],k[1010011],t[10101][10101];
vector<long long int> v[1010101];
long long int vis[1010101],sum=0,last=0;
void dfs(long long int u,long long int fa)
{
	sum+=w[u]+t[u][u]+t[u][last];
	if(u==fa)
	{
		return ;
	}
	last=u;
	vis[u]=1;
	for(auto i:v[u])
	{
		if(vis[i]==0)
		{
			dfs(i,fa);
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long int i=1;i<=m;i++) 
	{
		cin>>w[i];
	}
	for(long long int i=1;i<=n;i++)
	{
		cin>>k[i];
		long long int lat=i;
		for(long long int j=1;j<=k[i];j++)
		{
			long long int x;
			cin>>x>>t[i][j];
			v[lat].push_back(x);lat=x;
		}
	} 
	while(q--)
	{
		long long int s,t;
		cin>>s>>t;
		memset(vis,0,sizeof(vis));
		long long int sum=0;
		dfs(s,t); 
		cout<<sum<<endl;
	}
}
