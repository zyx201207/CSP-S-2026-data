#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=LLONG_MAX>>2;
int c,n,m,d,q,x,y,w[500001],dis[501][501],ans;
vector<pair<int,int>> stop[500001];
signed main()
{
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i!=j)*inf;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		while(c--)
		{
			cin>>x>>y;
			for(auto to:stop[x]) dis[i][to.first]=dis[to.first][i]=min(dis[i][to.first],y+to.second);
			stop[x].push_back({i,y});
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) if(i!=k) for(int j=1;j<=n;j++) if(j!=i&&j!=k) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		cin>>x>>y,ans=inf;
		for(auto u:stop[x]) for(auto v:stop[y]) ans=min(ans,u.second+v.second+dis[u.first][v.first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
