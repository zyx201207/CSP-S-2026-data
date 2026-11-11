#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct daan{
	long long bh,t;
};
long long n,m,d,q,w[500001],dp[501][501],ls[2][500001];
vector<daan>v[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,127,sizeof(dp));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int z=1;z<=m;z++)
	  cin>>w[z];
	for(int z=1;z<=n;z++)
	{
		dp[z][z]=0;
		long long k;
		cin>>k;
		for(int y=1;y<=k;y++)
		{
			cin>>ls[0][y]>>ls[1][y];
			for(int x=0;x<v[ls[0][y]].size();x++)
			{
				dp[z][v[ls[0][y]][x].bh]=min(dp[z][v[ls[0][y]][x].bh],ls[1][y]+v[ls[0][y]][x].t);
				dp[v[ls[0][y]][x].bh][z]=min(dp[v[ls[0][y]][x].bh][z],ls[1][y]+v[ls[0][y]][x].t);
			}
		}
		
		for(int y=1;y<=k;y++)
		  v[ls[0][y]].emplace_back((daan){z,ls[1][y]});
	}
	for(int z=1;z<=n;z++)
	  for(int y=1;y<=n;y++)
		for(int x=1;x<=n;x++)
		  if(dp[y][z]!=dp[0][0]&&dp[z][x]!=dp[0][0])
			dp[y][x]=min(dp[y][x],dp[y][z]+dp[z][x]);
	for(int z=1;z<=q;z++)
	{
		long long j,k,ret=1e18;
		cin>>j>>k;
		for(int y=0;y<v[j].size();y++)
		  for(int x=0;x<v[k].size();x++)
			ret=min(ret,dp[v[j][y].bh][v[k][x].bh]+v[j][y].t+v[k][x].t);
		cout<<ret+w[j]+w[k]<<"\n";
	}
	return 0;
}
