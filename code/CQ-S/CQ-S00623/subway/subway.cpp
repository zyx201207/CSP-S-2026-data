#include<bits/stdc++.h>
using namespace std;
#define M 505
#define N 500005
#define int long long
#define INF 1000000000000000000
namespace lzz
{
	int c,n,m,D,Q;
	int sz[M]; vector<int>a[M],t[M];
	int w[N],d[M][M]; vector<pair<int,int> >q[N];
	int main()
	{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		//m是站数,n是线路数!!! 
		cin>>c>>n>>m>>D>>Q;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>sz[i],a[i].resize(sz[i]+1),t[i].resize(sz[i]+1);
			for(int j=1;j<=sz[i];j++)cin>>a[i][j]>>t[i][j],q[a[i][j]].push_back({i,t[i][j]}); for(int j=1;j<=n;j++)d[i][j]=INF; d[i][i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			for(pair<int,int>pos1:q[i])
			{
				for(pair<int,int>pos2:q[i])d[pos1.first][pos2.first]=min(d[pos1.first][pos2.first],pos1.second+pos2.second);
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
		while(Q--)
		{
			int u,v,ans=INF; cin>>u>>v;
			for(pair<int,int>pos1:q[u])
			{
				for(pair<int,int>pos2:q[v])ans=min(ans,pos1.second+d[pos1.first][pos2.first]+pos2.second);
			}cout<<ans+w[u]+w[v]<<'\n';
		}


		return 0;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}

