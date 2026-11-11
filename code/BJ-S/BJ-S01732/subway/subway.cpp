#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=505;
const int M=5e5+5;

int add[M], cnt[M], f[N][N], x[25], d[25];
pair<int,int> vec[M][25];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,D,q;
	cin >> c >> n >> m >> D >> q;
	for(int i=1;i<=m;i++)
		scanf("%lld",&add[i]);

	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%lld %lld",&a,&t);
			vec[a][++cnt[a]]=make_pair(t,i);
		}
	}

	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][i]=0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i];j++)
			x[j]=vec[i][j].second, d[j]=vec[i][j].first;

		for(int j=1;j<=cnt[i];j++)
			for(int k=1;k<j;k++)
			{
				f[x[j]][x[k]]=min(f[x[j]][x[k]],d[j]+d[k]);
				f[x[k]][x[j]]=min(f[x[k]][x[j]],d[j]+d[k]);
			}
	}

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%lld %lld",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=cnt[x];i++)
			for(int j=1;j<=cnt[y];j++)
				ans=min(ans,vec[x][i].first+vec[y][j].first+f[vec[x][i].second][vec[y][j].second]);
		printf("%lld\n",ans+add[x]+add[y]);
	}
	return 0;
}