#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int f[10500][10500];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	memset(f,0x3f3f3f,sizeof(f));
	for(int i = 1;i <= m;i++)
	{
		cin >> f[i][m + i];
		f[m + i][i] = f[i][m + i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int a,b;
			cin >> a >> b;
			f[m + a][2 * m + i] = b;
			f[2 * m + i][m + a] = b;
		}
	}
	for(int k = 1;k <= 2 * m + n;k++)
	{
		for(int i = 1;i <= 2 * m + n;i++)
		{
			for(int j = 1;j <= 2 * m + n;j++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	int l,r;
	while(q--)
	{
		cin >> l >> r;
		cout << f[l][r] << endl;
	}
	return 0;
}
