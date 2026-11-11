#include <bits/stdc++.h>
using namespace std;
long long dis[507][507];
int w[500007];
map<int,int> t[507];
vector<int> tong[500007];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			dis[i][j]=1e17;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int a,t1;
			cin>>a>>t1;
			t[i][a]=t1;
			for(int r=0;r<tong[a].size();r++)
			{
				dis[tong[a][r]][i]=dis[i][tong[a][r]]=min(dis[tong[a][r]][i],1ll*t1+t[tong[a][r]][a]);
			}
			tong[a].push_back(i);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		long long ans=1e17;
		for(int i=0;i<tong[st].size();i++)
		{
			for(int j=0;j<tong[ed].size();j++)
			{
				ans=min(ans,dis[tong[st][i]][tong[ed][j]]+t[tong[st][i]][st]+t[tong[ed][j]][ed]);
			}
		}
		cout<<ans+w[st]+w[ed]<<'\n';
	}
	return 0;
}
