#include<bits/stdc++.h>
#define PII pair<long long,long long>
using namespace std;
const int N=1050,M=500500;
long long c,n,m,d,q,a[M],k[N],f[M];
long long s,e,ans;
vector<PII >st[M],sq[M];
long long bfs(long long x)
{
	queue<pair<long long,long long> >q;
	q.push({x,0});
	f[x]=0;
	while(!q.empty())
	{
		long long x=q.front().first,y=q.front().second;
		q.pop();
		if(x==e)
		{
			ans=min(y,ans);
		}
		for(PII i:sq[x])
		{
			y+=i.second;//
			for(PII j:st[i.first])
			{
				long long u=j.first,v=j.second;//vÊÇ½øÕ¾ 
				if(f[u]<=y+v) continue;
				f[u]=y+v;
				q.push({u,y+v});
			}
			y-=i.second;
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
		{
			long long x,y;
			cin>>x>>y;
			st[i].push_back({x,y});
			sq[x].push_back({i,y});
		}
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>s>>e;
		for(long long j=1;j<=m;j++) f[j]=1e18;
		ans=1e18;
		long long as=bfs(s);
		cout<<as+a[s]+a[e]<<'\n';
	}
	
	return 0;
}
