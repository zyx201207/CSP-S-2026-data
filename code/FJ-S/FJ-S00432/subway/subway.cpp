#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[500510],v,l,k[500510],lj[510][510],u,ans,x,y;
vector<pair<int,int> > a[500510],t[500510];
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	memset(lj,0x3f,sizeof lj);
	cin>>c>>m>>n>>d>>q;
	for (int i=1;i<=n;i++) cin>>w[i];
	for (int i=1;i<=m;i++)
	{
		cin>>k[0];
		for (int j=1;j<=k[0];j++)
		{
			cin>>v>>l;
			a[v].push_back(make_pair(i,l));
		}
	}
	for (int i=1;i<=n;i++)
	{
		k[i]=a[i].size();
		for (int j=1;j<k[i];j++)
		{
			for (int l=0;l<j;l++)
			{
				u=a[i][j].first,v=a[i][l].first;
				lj[u][v]=lj[v][u]=min(lj[u][v],a[i][j].second+a[i][l].second);
			}
		}
	}
	for (int i=1;i<=m;i++) lj[i][i]=0;
	for (int k=1;k<=m;k++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<i;j++)
			{
				if (lj[i][k]!=INF && lj[k][j]!=INF) lj[i][j]=lj[j][i]=min(lj[i][j],lj[i][k]+lj[k][j]);
			}
		}
	}
//	for (int i=1;i<=m;i++)
//	{
//		for (int j=1;j<=m;j++)
//		{
//			cout<<lj[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while (q--)
	{
		cin>>x>>y;
		ans=INF;
		for (int i=0;i<k[x];i++)
		{
			for (int j=0;j<k[y];j++)
			{
				u=a[x][i].first,v=a[y][j].first;
				ans=min(ans,lj[u][v]+a[x][i].second+a[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

