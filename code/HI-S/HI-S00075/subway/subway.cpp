#include <bits/stdc++.h>
using namespace std;
int c,n,m,d;
int u,e,r;
int wa[500010],k[510];
int a[510][500010],t[510][500010];
long long ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n;
	cin >> m >> d >> u;
	for(int i=1;i<=m;i++)
	{
		cin >> wa[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=u;i++)
	{
		ans=0;
		cin >> e >> r;
		ans+=wa[e];
		ans+=wa[r];
		for(int j=e;j<=r-1;j++)
		{
			for(int z=j;z<=r;z++)
			{
				ans+=t[j][z];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
