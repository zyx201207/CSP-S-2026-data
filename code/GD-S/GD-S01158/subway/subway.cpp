#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e2+5,maxm=5e5+5,inf=1e15;
int n,m,Q,w[maxm];
int c[maxn][maxn];
vector<pair<int,int> >aa[maxm];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int id_,D;
	cin>>id_>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=inf,c[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int T;
		cin>>T;
		while(T--)
		{
			int x,v;
			cin>>x>>v;
			aa[x].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++)
	{
		int siz=aa[i].size();
		for(int j=0;j<siz;j++)
		{
			for(int l=0;l<j;l++)
			{
				int x=aa[i][j].first,y=aa[i][l].first,val=aa[i][j].second+aa[i][l].second;
				c[x][y]=c[y][x]=min(c[x][y],val);
			}
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(c[i][l]+c[l][j]<c[i][j])c[i][j]=c[i][l]+c[l][j];
			}
		}
	}
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=inf;
		for(int i=0;i<aa[x].size();i++)
		{
			for(int j=0;j<aa[y].size();j++)
			{
				int X=aa[x][i].first,Y=aa[y][j].first;
				int val=aa[x][i].second+aa[y][j].second;
				ans=min(ans,val+c[X][Y]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
WarThunder
*/
