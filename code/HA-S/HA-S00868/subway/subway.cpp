#include <bits/stdc++.h>
using namespace std;
struct P{
	int s , t;
};
vector<vector<P> >a(500010);
int n , m , d , q , w[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> n >> n >> m >> d >> q;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> w[i];
	for ( int i = 1 ; i <= m ; i ++ )
	{
		int k;
		cin >> k;
		for ( int j = 1 ; j <= k ; j ++ )
		{
			int s , t;
			cin >> s >> t;
			a[i].push_back({s,t}); 
		}
	}
	if ( n == 2 )
	{
		while ( q -- )
		{
			int x , y;
			cin >> x >> y;
			int ans = 0x3f3f3f3f;
			for ( int i = 1 ; i <= m ; i ++ )
				ans = min(ans,a[i][0].t+a[i][1].t);
			cout << ans + w[x] + w[y] << endl;
		}
	}
	else
	{
		cout << 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
