#include<bits/stdc++.h>

using namespace std;

long long c,n,m,d,q,w[500010],k[555],a[555][500010],t[555][500010],dist[500010];
bool st[500010];
vector<long long> g[555];
void dfs(long long x)
{
	queue<long long> q;
	q.push(x);
	memset(dist,0x3f,sizeof dist);
	dist[x]=0;
	while(q.size())
	{
		auto x=q.front();
		q.pop();
		for(long long y:g[x])
		{
			dist[y]=min(dist[x]+t[x][y],dist[y]);
			q.push(y);
		}
	}
}
long long work(long long x,long long y)
{

	dfs(x);
	return dist[y]+w[x]+w[y];
}

int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){cin>>k[i];for(long long j=1;j<=k[i];j++){cin>>a[i][j]>>t[i][j];}}
	for(long long i=1;i<=n;i++)for(long long j=1;j<=k[i];j++){if(st[a[i][j]])t[i][j]*=2;else st[a[i][j]]=1;}
	for(long long i=1;i<=n;i++)for(long long j=1;j<=k[i];j++){g[i].push_back(j);}
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		cout<<work(x,y)<<"\n";
	}
	return 0;
}
