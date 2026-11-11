#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=500+10,inf=9e18;
int w[N];
int insub[N][M];
vector<pair<int,int>> sub[M],inw[N];
int dis[M][M];
bitset<N> tmp;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,t;
			cin>>x>>t;
			insub[x][i]=t;
			sub[i].push_back({x,t});
			inw[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		for(int j=1;j<=n;j++)
		{
			for(auto [x,t]:sub[i])
			{
				if(!insub[x][j])
				{
					continue;
				}
				dis[i][j]=min(dis[i][j],t+insub[x][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(k==i)continue;
			for(int j=1;j<=n;j++)
			{
				if(k==j||i==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cerr<<dis[i][j]<<" ";
		}
		cerr<<'\n';
	}*/
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		int ans=inf;
		for(auto [i,t1]:inw[a])
		{
			for(auto [j,t2]:inw[b])
			{
				ans=min(ans,dis[i][j]+t1+t2);
			}
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}
//检查要不要卡常