#include <bits/stdc++.h>
using namespace std;
const int N = 1e9+2;
long long c,n,m,d,q;
long long a[505][505],t[505][505],k[505],w[505],x[N],y[N],f[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= N;i++)
	{
		 f[i]= 1000000; 
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 1;i <= q;i++)
	{
		for (int j = x[i];j <= y[i];j++)
		{
			if (a[1][x[i]]==a[q][y[i]])
			{
				cout << w[x[i]] + t[a[x[i]]][i]+w[y[i]];
				return 0;
			}
			else
			{
				
			}
		}
	}
	
}
