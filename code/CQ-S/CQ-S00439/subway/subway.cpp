#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,D,q;
int dis[501][501];
int a[500001];
vector<pair<int,int>>e[500001];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			e[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	int inf=dis[0][0];
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(pair<int,int>A:e[i])
		{
			int x=A.first,w1=A.second; 
			for(pair<int,int>B:e[i])
			{
				int y=B.first,w2=B.second;
				dis[x][y]=dis[y][x]=min(dis[x][y],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=2e18;
		for(pair<int,int>A:e[x]) for(pair<int,int>B:e[y]) if(dis[A.first][B.first]<=inf) ans=min(ans,a[x]+a[y]+dis[A.first][B.first]+A.second+B.second);
		cout<<ans<<"\n"; 
	}
	return 0;
}
