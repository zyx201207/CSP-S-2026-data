#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#define cin lyc
#define cout lmy
long long dis[505][505];
ifstream cin("subway.in");
ofstream cout("subway.out");
long long c,n,m,d,q,w[500005];
vector<pair<int,long long>> g[500005];
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1,a,t;j<=k;j++)	cin>>a>>t,g[a].emplace_back(i,t);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:1e18);
	for(int i=1;i<=m;i++)
		for(auto e1:g[i])
			for(auto e2:g[i])
				dis[e1.first][e2.first]=min(dis[e1.first][e2.first],e1.second+e2.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto e1:g[x])
			for(auto e2:g[y])
				ans=min(ans,e1.second+e2.second+dis[e1.first][e2.first]);
		cout<<(w[x]+w[y]+ans)<<endl;
	}
}