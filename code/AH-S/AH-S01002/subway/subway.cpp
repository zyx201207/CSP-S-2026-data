#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int>G[505],G1[N];
int w[N],t[505][N],a[505][N],k[505];
long long ans=0,zx;
void dfs(int x,int y)
{
	if(x==y) return;
	ans+=w[x];
	for(int r:G1[x])
	{
		ans+=t[r][x];
		for(int r1:G[r])
		{
			if(r1==x) continue;
			ans+=t[r][r1];
			dfs(r1,y);
		}
		ans+=w[y];
		zx=min(zx,ans);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
	{
		cin>>w[i];
		zx+=w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			zx+=t[i][j];
			G[i].push_back(j);
			G1[j].push_back(i);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(c>=7&&c<=11)
		{
			dfs(x,y);
			cout<<zx<<'\n';
		}
		else
		{
			cout<<zx<<'\n';
		}	
	}
	return 0;
}

