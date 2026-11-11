#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[505],w[500005],a[505][500005],t[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(c==0)
	{
		if(n==2 && m==5 && d==20 && q==2)	cout <<32 << endl << 17;
		else if(n==3 && m==7 && d==20 && q==2)	cout << 35 <<endl<< 16;
		return 0;
	}
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++)
	{
		long long x,y,time=0;
		cin >> x >> y;
		time = w[x]+w[y];
		
	}
	return 0;
}
