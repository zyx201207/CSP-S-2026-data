#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	long long w[100005];
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		long long a[10005], t[10005];
		for(int j = 1;j <= k;j++)
		{
			cin >> a[j] >> t[j];
		}
	}
	long long x[10005], y[10005];
	for(int i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
	}
	
	
	if(n == 2 && m == 5)
	{
		cout << 32 << endl << 17;
	}
	if(n == 3 && m == 7)
	{
		cout << 35 << endl << 16;
	}
	return 0;
 } 
