#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL w[510];
int f[510],dis[510];
LL dp[510][510];
int k,t[510][510],a[510][510],g[510][510];
int c,n,m,d,q;
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(g[i][j]==0) g[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
		g[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
		g[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
	}
	floyd();
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		LL ans=w[l]+w[r];
		cout<<g[l][r]+ans<<'\n';
	}
}
