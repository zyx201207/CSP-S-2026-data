#include <bits/stdc++.h>
using namespace std;
int c,n, m, d, q,k[505],a[505][500005],x[100005],y[100005];
long long w[500005],t[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i =1; i<=n; i++)
	{
		cin>>w[i];
	}
	for (int i =1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i] ; i++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int z =1; z <= q; z++)
	{
		long long sum=0;
		int l, r;
		for (int i =1; i <= n; i++)
		{
			for (int j = 1; j <= k[i]; j++)
			{
				if (a[i][j] == x[z]){
					sum +=t[i][j];
					l = i;
				}
				else if(a[i][j] == y[z]){
					sum += t[i][j];
					r = i;
				}
			}
		}
		sum += w[x[z]] + w[y[z]];
		for(int i = 1; i <= abs(l-r);i++)
		{
			sum += t[l][t[i][1]] + t[r][t[i][1]];
		}
		cout << sum << "\n";
	}
	return 0;
}
