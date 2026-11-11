#include<bits/stdc++.h>
using namespace std;

int w[500005] = {};
int a[505][500005] = {};
int t[505][500005] = {};
int u[505][500005] = {};

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a[i][j] >> t[i][j];
			u[i][a[i][j]] = j;
		}
	}
	for(int i = 1;i <= q;i++)
	{
		int x,y;
		cin >> x >> y;
		for(int j = 1;j <= n;j++)
		{
			long long num = 0;
			if(u[j][x])
			{
				num += t[j][u[j][x]];
				n1 = x;
				while(n1 == y)
				{
					int 
				}
				
			}
		}
	}
	return 0;
}
