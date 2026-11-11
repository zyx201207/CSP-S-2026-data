#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],dis[505][505];
vector<int>li[500005],ti[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int gs,a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>gs;
		while(gs--)
		{
			cin>>a>>b;
			li[a].push_back(i);ti[a].push_back(b);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<li[i].size();j++)
			for(int k=j+1;k<li[i].size();k++)
				dis[li[i][k]][li[i][j]]=dis[li[i][j]][li[i][k]]=min(dis[li[i][j]][li[i][k]],ti[i][j]+ti[i][k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
	while(q--)
	{
		gs=4e18;
		cin>>a>>b;
		for(int i=0;i<li[a].size();i++)
			for(int j=0;j<li[b].size();j++)
				gs=min(gs,w[a]+w[b]+ti[a][i]+ti[b][j]+dis[li[a][i]][li[b][j]]);
		cout<<gs<<'\n';
	}
	return 0;
}

