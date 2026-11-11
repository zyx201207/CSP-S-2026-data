#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long c,n,m,d,q,w[500010],k[510],dis[510][510];
vector <pair<long long,long long> > ro[500010],edge[510];
bool vis[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			ro[a].emplace_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		sort(ro[i].begin(),ro[i].end());
		for(int j=0;j<ro[i].size();j++)
		{
			for(int l=j+1;l<ro[i].size();l++)
			{
				dis[ro[i][j].first][ro[i][l].first]=min(dis[ro[i][j].first][ro[i][l].first],ro[i][j].second+ro[i][l].second);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=j+1;l<=n;l++)
			{
				dis[j][l]=min(dis[j][l],dis[min(i,j)][max(i,j)]+dis[min(i,l)][max(i,l)]);
			}
		}
	}
	while(q--)
	{
		int l,r;
		long long ans=inf;
		cin>>l>>r;
		for(pair <long long,long long> A:ro[l])
		{
			for(pair <long long,long long> B:ro[r])
			{
				ans=min(ans,dis[min(A.first,B.first)][max(A.first,B.first)]+A.second+B.second);
			}
		}
		cout<<ans+w[l]+w[r]<<'\n';
	}
}
