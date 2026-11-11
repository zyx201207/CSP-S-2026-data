#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
constexpr int N=505,M=5e5+5;
constexpr long long INF=0x3f3f3f3f3f3f3f3f;
int C,n,m,D,Q;
long long w[M],f[N][N];
vector<pair<int,long long> > p[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();n=read();m=read();D=read();Q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,x;i<=n;i++)
	{
		x=read();
		for(int j=1,y,t;j<=x;j++) y=read(),t=read(),p[y].emplace_back(i,t);
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int siz=p[i].size();
		for(int j=0;j<siz;j++)
			for(int k=j+1;k<siz;k++)
			{
				int x=p[i][j].first,y=p[i][k].first;
				f[x][y]=f[y][x]=min(f[x][y],p[i][j].second+p[i][k].second);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int u,v;Q--;)
	{
		u=read();v=read();
		long long res=INF;
		for(auto pu:p[u])
			for(auto pv:p[v])
				res=min(res,pu.second+pv.second+f[pu.first][pv.first]);
		res+=w[u]+w[v];
		printf("%lld\n",res);
	}
	return 0;
}
