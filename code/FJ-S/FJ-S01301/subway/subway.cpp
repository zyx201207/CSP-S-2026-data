#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct node
{
	int id,num;
};
vector<node> e[N];
int f[505][505];
int pw[N];
int c,n,m,d,q;

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%lld",&pw[i]);
	}
	for (int i=1;i<=n;i++)
	{
		int len;
		scanf("%lld",&len);
		for (int j=1;j<=len;j++)
		{
			int t1,t2;
			scanf("%lld%lld",&t1,&t2);
			e[t1].push_back({i,t2});
		}
	}
	
	memset(f,0x3f3f3f3f,sizeof(f));
	for (int i=0;i<=n;i++)
	{
		f[i][i]=0;
	}
	for (int i=1;i<=m;i++)
	{
		for (int j1=0;j1<e[i].size()-1;j1++)
		{
			for (int j2=j1+1;j2<e[i].size();j2++)
			{
				int v1=e[i][j1].id,w1=e[i][j1].num;
				int v2=e[i][j2].id,w2=e[i][j2].num;
				f[v1][v2]=f[v2][v1]=min(f[v1][v2],w1+w2);
			}
		}
	}
	
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			if (i==k) continue;
			for (int j=1;j<=n;j++)
			{
				if (k==j||i==j) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	while (q--)
	{
		int ans=1e18;
		int t1,t2;
		scanf("%lld%lld",&t1,&t2);
		for (int j1=0;j1<e[t1].size();j1++)
		{
			for (int j2=0;j2<e[t2].size();j2++)
			{
				int v1=e[t1][j1].id,w1=e[t1][j1].num;
				int v2=e[t2][j2].id,w2=e[t2][j2].num;
				ans=min(ans,pw[t1]+w1+pw[t2]+w2+f[v1][v2]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

