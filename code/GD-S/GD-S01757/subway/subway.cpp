#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1005],k[505],t[1005],a[1005];
long long e[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	memset(e,0x3f,sizeof(e));
	for(long long i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	if(7<=c && c<=11)
	{
		for(long long i=1;i<=n;i++)
		{
			cin >> k[i];
			if(k[i]==1) continue;
			long long x,y,t,tt;
			cin >> x >> t >> y >> tt;
			e[x][y]=t+tt;
			e[y][x]=t+tt;
		}
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			cin >> k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin >> a[j] >> t[j];
				for(int k=1;k<j;k++)
				{
					e[a[k]][a[j]]=t[k]+t[j];
					e[a[j]][a[k]]=t[k]+t[j];
				}
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			for(long long k=1;k<=m;k++)
			{
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++)
	{
		int x,y;
		cin >> x >> y;
		cout << e[x][y]+w[x]+w[y] <<endl;
	}
	return 0;
} 
