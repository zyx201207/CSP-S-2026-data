#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=510;
int n,m,d,q,c,dis[M][M],w[N],minn;
vector<pair<int,int > > x[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++)
		for(int t=1;t<=m;t++) dis[i][t]=1e18;
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++) x[i].clear();
	for(int i=1;i<=n;i++) cin>>w[i-1];
	for(int i=1;i<=m;i++)
	{
		int s;
		cin>>s;
		for(int t=1;t<=s;t++)
		{
			int a,b;
			cin>>a>>b;
			x[a].push_back({i,b});
			for(auto j : x[a])
			{
				if(j.first==i) continue;
				dis[i][j.first]=j.second+b;
				dis[j.first][i]=j.second+b;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int t=1;t<=m;t++)
		{
			if(t==i) continue;
			for(int j=1;j<=m;j++)
				if(dis[i][t]>dis[i][j]+dis[t][j]) dis[i][t]=dis[i][j]+dis[t][j];
		}
	}
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		minn=1e18;
		for(auto i : x[a])
		{
			for(auto t : x[b])
			{
				minn=min(minn,dis[i.first][t.first]+i.second+t.second);
			}
		}
		cout<<minn+w[a-1]+w[b-1]<<'\n';
		minn=1e18;
	}
}
