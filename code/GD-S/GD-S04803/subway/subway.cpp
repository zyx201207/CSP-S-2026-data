#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	long long u,w;
	bool operator <(node c) const
	{
		return w>c.w;
	}
};
long long c,n,m,d,q;
long long a[500005];
vector<node> e[505];
vector<node> e2[500005];
vector<node> e3[505];
long long b[505][505];
bool vis[505];
long long dp[505][505];
//void solve()
//{
//	memset(vis,false,sizeof(vis));
//	memset(dp,127,sizeof(dp));
//	long long xr,yr;
//	cin>>xr>>yr;
//	priority_queue<node> q;
//	q.push({xr,a[xr]});
//	while(!q.empty())
//	{
//		node nk=q.top();
//		q.pop();
//		if(vis[nk.u])
//		{
//			continue;
//		}
//		vis[nk.u]=true;
//		if(nk.u==yr)
//		{
//			cout<<nk.w+a[yr]<<"\n";
//		}
//		for(long long j=0;j<e[nk.u].size();j++)
//		{
//			node kop=e[nk.u][j];
//			if(dp[kop.u]>dp[nk.u]+kop.w)
//			{
//				dp[kop.u]=dp[nk.u]+kop.w;
//				q.push({kop.u,dp[kop.u]});
//			}
//		}
//	}
//}
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
	memset(b,127,sizeof(b));
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			long long p,f;
			cin>>p>>f;
			e3[i].push_back({p,f});
			e2[p].push_back({i,f});
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<e3[i].size();j++)
		{
			long long zhan=e3[i][j].u;
			for(long long k=0;k<e2[zhan].size();k++)
			{
				long long xian=e2[zhan][k].u;
				if(xian==i)
				{
					b[i][xian]=0;
					continue;
				}
				b[i][xian]=min(e3[i][j].w+e2[zhan][k].w,b[i][xian]);
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			if(b[i][j]<1e10)
			{
				e[i].push_back({j,b[i][j]});
			}
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<i<<":\n";
//		for(long long k=0;k<e[i].size();k++)
//		{
//			node p=e[i][k];
//			cout<<p.u<<" "<<p.w<<"\n";
//		}
//		cout<<"---------------\n";
//	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			dp[i][j]=b[i][j];
			if(dp[i][j]>1e12)
			{
				dp[i][j]=1e12;
			}
		}
	}
	
	for(long long k=1;k<=n;k++)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long j=1;j<=n;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(long long i=1;i<=q;i++)
	{
		long long xr,yr;
		cin>>xr>>yr;
		long long minn=1e12;
		for(long long i=0;i<e2[xr].size();i++)
		{
			node p1=e2[xr][i];
			for(long long j=0;j<e2[yr].size();j++)
			{
				node p2=e2[yr][j];
				minn=min(minn,dp[p1.u][p2.u]+p1.w+p2.w);
			}
		}
		minn+=a[xr]+a[yr];
		cout<<minn<<"\n";
	}
}
