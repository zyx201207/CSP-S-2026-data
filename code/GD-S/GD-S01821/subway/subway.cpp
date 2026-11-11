#include<bits/stdc++.h>
using namespace std;
long long csd,n,m,d,q,w[500010],k[500010],f[510][510];
vector<long long> a[510],t[510];
vector<pair<long long,long long> > id[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(f,0x3f,sizeof(f));
	cin>>csd>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		f[i][i]=0;
		for(long long j=1,x,y;j<=k[i];j++)
		{
			cin>>x>>y;
			id[x].push_back({i,y});
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(long long i=1;i<=m;i++)
	{
		for(long long x=1;x<id[i].size();x++)
		{
			for(long long y=0,len=0;y<x;y++)
			{
				len=id[i][x].second+id[i][y].second;
				if(len<f[id[i][x].first][id[i][y].first])
				{
					f[id[i][x].first][id[i][y].first]=f[id[i][y].first][id[i][x].first]=len;
				}
			}
		}
	}
	for(long long l=1;l<=n;l++)
	{
		for(long long i=1;i<=n;i++)
		{
			if(i==l) continue;
			for(long long j=1;j<=n;j++)
			{
				if(j==l || j==i) continue;
				if(f[i][l]+f[l][j]<f[i][j])
				{
					f[i][j]=f[i][l]+f[l][j];
				}
			}
		}
	}
	while(q--)
	{
		long long x,y,ans=1000000000000000000ll;
		cin>>x>>y;
		for(pair<long long,long long> i:id[x])
		{
			for(pair<long long,long long> j:id[y])
			{
				ans=min(ans,i.second+j.second+f[i.first][j.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
