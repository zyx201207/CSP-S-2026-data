#include<bits/stdc++.h>
#define ll long long
#define SNSNMO 110
using namespace std;
const int MAXN=10,MAXM=500010;

int c,n,m,d,q,ans;
int k[MAXN],w[MAXM],a[MAXN][MAXM],t[MAXN][MAXM],cz[MAXN][MAXM]={0},jg[MAXM][3]={0};
/*void dfs(int x,int z,int zd,int bs)
{
	if(x==zd)
	{
		ans=min(ans,bs);
		return;
	}
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i]*2;++j)
		{
			cin>>a[k[i]][j]>>t[k[i]][j];
			cz[k[i]][a[k[i]][j]]=1;
			jg[a[k[i]][j]][k[i]]=t[k[i]][j];
		}
	}
	int minj=0x3f3f3f3f;
	for(int i=1;i<=m;++i)
	{
		if(cz[1][i]&&cz[2][i]) minj=min(minj,jg[i][1]+jg[i][2]);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		if(cz[1][x]&&cz[1][y])
		{
			cout<<ans<<'\n';
			continue;
		}
		if(cz[2][x]&&cz[2][y])
		{
			cout<<ans<<'\n';
			continue;
		}
		else
		{
			cout<<ans+minj<<'\n';
			continue;
		}
	}
	return 0;
}
