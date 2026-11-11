#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[500005],k,a[55][500005][2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}//5*10^5
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a[i][j][0] >> a[i][j][1];
		}
	}//5*10^5
	for(int i = 1;i <= q;i++)
	{
		int u,v;
		cin >> u >> v;
		int ans = 0;
		ans += w[u];
		ans += w[v];
		for(int ii = 1;ii <= n;ii++)
		{
			if(a[ii][v][0] != 0)
			{
				ans += a[ii][v][1];
				cout << ans;
			}
		}
	}//10^6
	return 0;
 } 
