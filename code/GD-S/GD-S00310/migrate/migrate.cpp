#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int N=2e3+10;
int a[N],f[N][N],dis[N][N];
int c,t;
int n,d;
 
int dfs(int l, int r)
{
//	printf("%d %d\n", l, r);
	if(f[l][r]) return f[l][r];
	dis[l][r]=1e18;
	if(a[r]-a[l]<=d) 
	{
		dis[l][r]=2;
		f[l][r]=1;
		return 1;
	}
	int res=0;
	for(int k=l+1; k<r; k++)
	{
		int x=dfs(l,k),y=dfs(k,r);
//		printf("%d %d %d %d %d\n", l, r, k, f[l][k], f[k][r]);
		if(dis[l][k]+dis[k][r]-1<dis[l][r])
		dis[l][r]=dis[l][k]+dis[k][r]-1,
		res=x*y;
		else if(dis[l][k]+dis[k][r]-1==dis[l][r])
		res+=x*y;
	}
//	printf("%d %d %d\n", l, r, f[l][r]);
	return f[l][r]=res;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld", &c, &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &d);
		for(int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
		int ans=0;
		memset(f,0,sizeof(f));
		memset(dis, 0x3f, sizeof(dis));
		for(int i=1; i<=n; i++)
		for(int j=i+1;j<=n;j++)
		{
			int x=dfs(i,j);
//			printf("%d %d %d\n", i, j, x); 
			if(x==2) ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
