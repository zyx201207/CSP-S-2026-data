#include<bits/stdc++.h>
using namespace std;
long long LYY,n,m,d,Q;
long long zk[500010],k[510];
vector<pair<long long,long long> >a[510];
vector<long long>b[500010];
long long c[510][510];
map<long long,long long>e[510],zhb[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>LYY>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>zk[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			long long x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
			zhb[i][x]=y;
			b[x].push_back(i*1ll);
			e[i][x]=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i][j]=1e18;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<k[i];j++)
		{
			long long T=b[a[i][j].first].size();
			for(long long l=0;l<T;l++)
			{
				c[i][b[a[i][j].first][l]]=min(c[i][b[a[i][j].first][l]],(a[i][j].second+e[b[a[i][j].first][l]][a[i][j].first]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		c[i][i]=0;
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(c[i][j]>c[i][l]+c[l][j])
				{
					c[i][j]=c[i][l]+c[l][j];
				}
			}
		}
	}
	while(Q--)
	{
		long long o,p;
		cin>>o>>p;
		long long l=b[o].size(),lp=b[p].size();
		long long ans=1e18;
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<lp;j++)
			{
				ans=min(ans,zhb[b[o][i]][o]+zhb[b[p][j]][p]+c[b[o][i]][b[p][j]]);
			}
		}
		cout<<zk[o]+zk[p]+ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
