#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
const ll MAXN=0x3f3f3f3f3f3f3f;
ll w[M],dis[N][N];
int k[N];
vector<pair<int,ll> > sw[M];
void solve(int n)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j]==0)
				dis[i][j]=MAXN;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,l,r;
	int x;
	ll y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x>>y;
			sw[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<sw[i].size();j++)
			for(int k=0;k<j;k++)
			{
				pair<int,ll> nx=sw[i][j],ny=sw[i][k];
				dis[nx.first][ny.first]=nx.second+ny.second;
				dis[ny.first][nx.first]=dis[nx.first][ny.first];
			}
	}
	solve(n);
	ll ans;
	while(q--)
	{
		ans=MAXN;
		cin>>l>>r;
		for(int i=0;i<sw[l].size();i++)
		{
			for(int j=0;j<sw[r].size();j++)
			{
				if(sw[l][i].first==sw[r][j].first)
					ans=min(ans,sw[l][i].second+sw[r][j].second);
				else
					ans=min(ans,dis[sw[l][i].first][sw[r][j].first]+sw[l][i].second+sw[r][j].second);
			}
		}//i==j
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}