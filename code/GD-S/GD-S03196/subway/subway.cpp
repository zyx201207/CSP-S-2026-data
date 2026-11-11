#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505,M = 5e5 + 5;
const ll inf = 2e18;
#define ll long long
ll f[N][N];
struct fw
{
	int u[22],len;
	ll t[22];
}a[M];
ll w[M],ans;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);	
	} 
	int k,u; 
	ll t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%lld",&u,&t);
			a[u].u[++a[u].len] = i;
			a[u].t[a[u].len] = t;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j] = inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=a[i].len;j++)
		{
			for(int k=1;k<=a[i].len;k++)
			{
				int x = a[i].u[j],y=a[i].u[k];
				if(x == y)
				{
					f[x][y] = 0;
				}
				else
				{
					f[x][y] = min(f[x][y],a[i].t[j] + a[i].t[k]);
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	ll sum;
	while(q--)
	{
		int x,y;
		
		scanf("%d%d",&x,&y);
		ans = w[x] + w[y];
		sum = inf;
		for(int i=1;i<=a[x].len ;i++)
		{
			for(int j=1;j<=a[y].len;j++)
			{
				int u = a[x].u[i],v = a[y].u[j];
//				if(f[u][v] == inf) continue;
				sum = min(sum,a[x].t[i] + a[y].t[j] + f[u][v]);
			}
		} 
		cout<<sum + ans ;
		cout<<endl;
//		if(q != 0)
//		{
//			cout<<',';
//		}
	}
	return 0;
}
