#include <bits/stdc++.h>
using namespace std;
long long n, m, c, d, q, x, y, w[505], k[2005], a[505][2005], t[505][2005];
bool f[505][2005];
long long check(int x, int y, long long sum = 0)
{
	if (x == y)
	    return sum;
	for (int i = 1; i <= n; i++)
		if (a[i][x] != 0)
		    sum = min(check(x + 1, y, w[i] + t[i][x]), sum);
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	/*c=编号，n=地铁线路数，m=地铁站数 d=经过路线 q=出行计划数*/
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= q; i++)
	{
	    cin >> k[i];
		for (int j = 1; j <= k[i] / 2; j++)
		    cin >> a[i][j] >> t[i][j];
	} 
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
	    cout << check(x, y, 0);  
	}
	return 0;
}
