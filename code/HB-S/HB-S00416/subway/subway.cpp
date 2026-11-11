#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=2e4+5,INF=0x3f3f3f3f;
int c,n,m,d,q,l,r,ans;
int w[M],k[N];
int a[N][M],t[N][M];
vector<int> liz[N];
int mp[N][N];
void add(int x)
{
	int len=liz[x].size();
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			mp[liz[x][i]][liz[x][j]]=t[liz[x][i]][x]+t[liz[x][j]][x];
			mp[liz[x][j]][liz[x][i]]=t[liz[x][i]][x]+t[liz[x][j]][x];
		}
	}
}
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
void solve()
{
	ans=INF;
	for(auto i:liz[l])
	{
		for(auto j:liz[r])
		{
			int x=w[l]+w[r]+t[i][l]+t[j][r]+mp[i][j];
			ans=min(x,ans);
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++) mp[i][j]=INF;
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++) 
		{
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][a[i][j]]);
			liz[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(liz[i].size()<=1) continue;
		add(i);
	}
	floyd();
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		solve();
		printf("%lld\n",ans);
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
