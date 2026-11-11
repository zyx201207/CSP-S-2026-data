#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=500010;
int cid,n,m,d,q,l[M],w[M],dis[N][N];
vector<pair<int,int> >a[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>cid>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,x,y;j<=k;j++)
			cin>>x>>y,a[x].push_back({i,y});
	}
	for(int i=1;i<=m;i++)
	{
		l[i]=a[i].size()-1;
		for(int j=0;j<l[i];j++)for(int k=j+1;k<=l[i];k++)
			dis[a[i][j].first][a[i][k].first]=dis[a[i][k].first][a[i][j].first]=
				min(dis[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1,x,y,minn;i<=q;i++)
	{
		cin>>x>>y,minn=1e18;
		for(int j=0;j<=l[x];j++)for(int k=0;k<=l[y];k++)
			minn=min(minn,w[x]+w[y]+a[x][j].second+a[y][k].second+dis[a[x][j].first][a[y][k].first]);
		cout<<minn<<'\n';
	}
	return 0;
}
