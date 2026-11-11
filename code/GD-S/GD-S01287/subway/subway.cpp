#include<bits/stdc++.h>
#define min(x,y) ((x)<(y)?x:y)
using namespace std;
const int maxn=5e5+5;
long long f[505][505];
vector<pair<int,long long>>p[maxn];
int c,n,m,d,q;
long long a[maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			long long w;
			cin>>x>>w;
			p[x].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)f[i][j]=1e15;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<p[i].size();j++)
		{
			for(int k=0;k<p[i].size();k++)
			{
				pair<int,long long> x=p[i][j],y=p[i][k];
				f[x.first][y.first]=min(f[x.first][y.first],x.second+y.second);
			}
		}
	}
	for(int mid=1;mid<=n;mid++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][mid]+f[mid][j],f[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long minn=1e15;
		int l,r;
		cin>>l>>r;
		for(int j=0;j<p[l].size();j++)
		{
			for(int k=0;k<p[r].size();k++)
			{
				minn=min(minn,p[l][j].second+p[r][k].second+f[p[l][j].first][p[r][k].first]);
			}
		}
		cout<<a[l]+a[r]+minn<<"\n";
	}
	return 0;
}
//-fsanitize=address,undefined

