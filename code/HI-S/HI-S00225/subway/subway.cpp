#include<bits/stdc++.h>
using namespace std;

const long long inf=0x3f3f3f3f3f3f3f3f;
const int qwq=1010;
int n,m,q,c,D;
long long w[qwq],d[qwq][qwq];
long long sum[qwq][qwq];
map<int,map<int,int> >mp;
namespace Hg
{
	inline void QvQ()
	{
		scanf("%d%d%d%d",&n,&m,&D,&q);
		memset(d,0x3f,sizeof d);
		for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
		int v[qwq],t[qwq];
		for(int num,i=1;i<=n;i++)
		{
			scanf("%d",&num);
			for(int j=1;j<=num;j++)
			{
				scanf("%d%lld",&v[j],&t[j]);
				for(int k=1;k<num;k++)
				{
					d[v[k]][v[j]]=t[k]+t[j];
				}
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
				}
			}
		}
		for(int x,y,i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",w[x]+w[y]+d[x][y]);
		}
	}
	inline void QwQ()
	{
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	}
	inline void Main()
	{
		scanf("%d%d%d%d",&n,&m,&D,&q);
		for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
		int v[qwq][qwq],t[qwq][qwq];
		for(int num,i=1;i<=n;i++)
		{
			scanf("%d",&v[i][0]);
			for(int j=1;j<=num;j++)
			{
				scanf("%d%lld",&v[i][j],&t[i][j]);
				mp[i][v[i][j]]=j;
				sum[i][j]=sum[i][j-1]+t[i][j];
			}
		}
		for(int x,y,i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				if(mp[i][x]<mp[i][y]) ans=min(sum[i][mp[i][y]]-sum[i][mp[i][x]-1],ans);
			}
			printf("%lld\n",ans+w[x]+w[y]);
		}
	}
}
int main()
{
	Hg::QwQ();
	scanf("%d",&c);
	if(c>=20&&c<=21) Hg::Main();
	else Hg::QvQ();
	return 0;
}
