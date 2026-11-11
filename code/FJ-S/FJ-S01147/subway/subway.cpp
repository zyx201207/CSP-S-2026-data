#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&~x) 
using namespace std;
const int N=501,M=2e5+10,Q=1e5+10;
int w[M],a[N][M],t[N][M],k[N],dis[M];
int ans[Q],xr[Q];
vector<int>qs[M];
vector<pair<int,int>>at[M];
int dfs(int p,int ed)
{
	if(p==ed)
	{
		return dis[p]=0;
	}
	if(dis[p]!=-1)
	{
		return dis[p];
	}
	dis[p]=INT_MAX;
	for(auto l:at[p])
	{
		int i=l.first,it=l.second;
		for(int j=1;j<=k[i];j++)
		{
			int q=a[i][j];
			if(p==q)
			{
				continue;
			}
//			if(ed==3&&p==2)
//			{
//				cout<<i<<' '<<q<<' '<<dfs(q,ed)<<' '<<t[i][p]<<' '<<t[i][q]<<'\n';
//			}
			dis[p]=min(dis[p],dfs(q,ed)+t[i][it]+t[i][j]);
		}
	}
	return dis[p];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			at[a[i][j]].push_back(make_pair(i,j));
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		cout<<i<<':';
//		for(auto j:at[i])
//		{
//			cout<<j<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=q;i++)
	{
		cin>>xr[i];
		int yr;
		cin>>yr;
		qs[yr].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		if(qs[i].empty())
		{
			continue;
		}
		memset(dis,-1,sizeof(dis));
//		cout<<i<<'\n';
		for(int j=1;j<=m;j++)
		{
			if(dis[j]==-1)
			{
				dis[j]=dfs(j,i);
			}
//			cout<<dis[j]<<' ';
		}
//		cout<<'\n';
		for(int j:qs[i])
		{
//			cout<<"  "<<w[xr[j]]<<' '<<w[i]<<' '<<dis[xr[j]]<<' '<<j<<'\n';
			ans[j]=w[xr[j]]+w[i]+dis[xr[j]];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<'\n';
	}
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

