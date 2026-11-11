#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k,a,t,dis[510][510],x,y,ans;
vector<pair<long long,long long> >lu[500010];
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			lu[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto j:lu[i])
		{
			for(auto j2:lu[i])
			{
				dis[j.first][j2.first]=min(dis[j.first][j2.first],j.second+j2.second);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int j2=1;j2<=n;j2++)
			{
				dis[j][j2]=min(dis[j][j2],dis[j][i]+dis[i][j2]);
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int j2=1;j2<=n;j2++)
			{
				dis[j][j2]=min(dis[j][j2],dis[j][i]+dis[i][j2]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int j2=1;j2<=n;j2++)
			{
				dis[j][j2]=min(dis[j][j2],dis[j][i]+dis[i][j2]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=1e16;
		for(auto j:lu[x])
		{
			for(auto j2:lu[y])
			{
				ans=min(ans,w[x]+w[y]+j.second+j2.second+dis[j.first][j2.first]);
			}
		}
		cout<<ans<<"\n";
	}
 	return 0;
}
