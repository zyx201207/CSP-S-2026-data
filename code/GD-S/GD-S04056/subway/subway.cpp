#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5+505;
const long long inf=1e18;
const long long mod=10000;
int w[maxn];
int c,n,m,d,q;
vector<long long> v[maxn];
long long dis[505][505];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(register int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(register int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(register int j=1,a,t;j<=k;j++)
		{
			cin>>a>>t;
			v[a].push_back(t*mod+i);
		}
		for(register int j=1;j<=n;j++)
		{
			if(i!=j)dis[i][j]=inf;
		}
	}
	for(register int i=1;i<=m;i++)
	{
		for(register int j=0;j<v[i].size();j++)
		{
			for(register int k=j+1;k<v[i].size();k++)
			{
				int a=v[i][j]%mod,b=v[i][k]%mod;
				dis[a][b]=min(dis[a][b],v[i][k]/mod+v[i][j]/mod);
				dis[b][a]=dis[a][b];
			}
		}
	}
	for(register int k=1;k<=n;k++)
	{
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	for(register int i=1,x,y;i<=q;i++)
	{
		long long ans=inf;
		cin>>x>>y;
		for(long long j:v[x])
		{
			for(long long k:v[y])
			{
				ans=min(dis[j%mod][k%mod]+j/mod+k/mod,ans);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
