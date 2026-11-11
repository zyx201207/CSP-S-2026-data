#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int c,n,m,d,q;
int a[600005];
int dij[600005],vis[600005];
vector<pair<int,int>> bian[600005];
int bian2[505][505];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int ai,t;
			cin>>ai>>t;
			bian[ai].push_back({n+i,t});
			bian[n+i].push_back({ai,t});
			//cout<<ai<<n+i<<t<<endl;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			bian2[i][j]=2e18;
	for(int i=1;i<=n;i++)
	{
		if(bian[i].size()<2)continue;
		for(int j1=0;j1<bian[i].size();j1++)
		{
			for(int j2=0;j2<bian[i].size();j2++)
			{
				if(j1==j2)continue;
				int hua=bian[i][j1].se+bian[i][j2].se;
				int t1=bian[i][j1].fi-n,t2=bian[i][j2].fi-n;
				bian2[t1][t2]=bian2[t2][t1]=min(hua,bian2[t1][t2]);
				//cout<<t1<<" "<<t2<<" "<<bian2[t1][t2]<<endl;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			vis[j]=0,dij[j]=2e18;
		dij[i]=0;
		p.push({0,i});
		while(p.size())
		{
			int now=p.top().se,dis=p.top().fi;
			p.pop();
			if(vis[now])continue;
			vis[now]=1;
			for(int jj=1;jj<=m;jj++)
			{
				int to=jj,hua=bian2[now][jj];
				if(vis[to])continue;
				if(dij[to]>dis+hua)
				{
					dij[to]=dis+hua;
					p.push({dis+hua,to});
				}
			}
		}
		for(int j=1;j<=m;j++)
			bian2[i][j]=dij[j];
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=2e18;
		for(int i=0;i<bian[x].size();i++)
		{
			for(int j=0;j<bian[y].size();j++)
			{
				ans=min(bian[x][i].se+bian[y][j].se+bian2[bian[x][i].fi-n][bian[y][j].fi-n],ans);
			}
		}
		cout<<ans+a[x]+a[y]<<endl;
	}
	return 0;
} 

