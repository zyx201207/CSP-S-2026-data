#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#define ll long long
#define dg(c) (c>='0'&&c<='9')
using namespace std;
const int N=5e5+10,M=510;
const ll Inf=2e18;
ll w[N],f[M][M];
vector<pair<int,ll>> G[N];
int rd()
{
	int res=0;
	char c=getchar();
	while(!dg(c))
		c=getchar();
	while(dg(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,a,p,x,y;
	ll ans,t;
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)
		w[i]=rd();
	for(int i=1;i<=n;i++)
	{
		p=rd();
		for(int j=1;j<=p;j++)
		{
			a=rd(),t=rd();
			G[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(i==j?0:Inf);
	for(int i=1;i<=m;i++)
		for(auto j:G[i])
			for(auto k:G[i])
				f[j.first][k.first]=min(f[j.first][k.first],j.second+k.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		ans=Inf;
		for(auto st:G[x])
			for(auto en:G[y])
				ans=min(ans,w[x]+st.second+w[y]+en.second+f[st.first][en.first]);
		printf("%lld\n",ans);
	}
	return 0;
}
