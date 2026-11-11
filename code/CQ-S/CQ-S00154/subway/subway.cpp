#include <iostream>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> k[i];
		for(int j = 1 ; j <= k[i] ; j ++)
		{
			cin >> a[i][j] >> t[a[i][j]];
			l[a[i][j]].push_back(i);
			e[a[i][j]][i].push_back({a[i - 1][j],0});
			e[a[i - 1][j]][i].push_back({a[i][j],0});
		}
	}
	while(q --)
	{
		int x,y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
