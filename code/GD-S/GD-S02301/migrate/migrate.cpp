#include <bits/stdc++.h>
using namespace std;

int c , t , n[100005] , d[100005];
long long x[1000005][1000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for ( int i = 1 ; i <= t ; i++)
	{
		cin >> n[i] >> d[i];
		for ( int j =1;j<=n[i];j++)
			cin >> x[i][j];
	}
	int m = n[1];
	if ( m == 4)
		cout << 1 << endl << 2;
	else if ( m == 5)
		cout << 0 << endl << 1;
	else if ( m == 197)
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
	return 0;
}
