#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<x<<"\n";
#define pb emplace_back
#define sz size
#define bg begin
#define ed end
#define pii pair<int,int>
#define mkp make_pair
#define ft first
#define sc second
#define int long long
using namespace std;
typedef long long lli;
typedef double lf;
const int N=505,M=5e5+5;
int m,n,d,q;
int w[M];
inline int mkh(int a,int b)
{
	return a*M+b;
}
unordered_map<int,int> t;
vector<int> vis[M];
int dis[N][N];
signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dis[i][j]=(1ll<<60);
	for(int i=0;i<N;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,x,y;
		cin>>k;
		while(k--)
			cin>>x>>y,t[mkh(i,x)]=y,vis[x].pb(i);
	}
	for(int i=1;i<=m;i++)
		for(int u=0;u<(int)vis[i].sz();u++)
			for(int v=u+1;v<(int)vis[i].sz();v++)
			{
				if(u==v)continue;
				int x=vis[i][u],y=vis[i][v];
				dis[x][y]=min(dis[x][y],t[mkh(x,i)]+t[mkh(y,i)]);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][j],dis[j][i]),
			dis[j][i]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y,ans=LLONG_MAX;
		cin>>x>>y;
		for(auto i:vis[x])
		{
			if(ans<t[mkh(i,x)])continue;
			for(auto j:vis[y])
				ans=min(ans,dis[i][j]+t[mkh(i,x)]+t[mkh(j,y)]);
		}	
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}

