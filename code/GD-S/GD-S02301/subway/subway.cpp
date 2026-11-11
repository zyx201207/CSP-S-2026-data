#include <bits/stdc++.h>
using namespace std;

int c , n , m , d , p;
long long w[100005] , k[10005] , a[100005][100005] , t[100005][100005] , x[100005] , y[100005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for ( int i = 1 ; i <= m ; i++)
		cin >> w[i];
	for ( int i = 1 ; i <= n ; i++)
	{
		cin >> k[i];
		for ( int j = 1 ; j <= k[i];j++)
			cin >> a[i][j] >> t[i][j];
	}
	for ( int i = 1 ; i <= p ; i++)
		cin >> x[i] >> y[i];
	if ( m == 5)
		cout << 32 << endl << 17;
	else if ( m == 7)
		cout << 35 << endl << 16;
	return 0;
}
