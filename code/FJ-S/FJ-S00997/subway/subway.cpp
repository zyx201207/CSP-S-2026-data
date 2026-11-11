#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];
ll dis[N][N];
vector<pair<int,int> >v[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y}); 
		}
	}
	memset(dis,0x3f3f3f3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto t1:v[i])
			for(auto t2:v[i])
				if(t1.first!=t2.first)
					dis[t1.first][t2.first]=dis[t2.first][t1.first]=t1.second+t2.second;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&i!=k)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(auto t1:v[x])
			for(auto t2:v[y])
				ans=min(ans,dis[t1.first][t2.first]+t1.second+t2.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
