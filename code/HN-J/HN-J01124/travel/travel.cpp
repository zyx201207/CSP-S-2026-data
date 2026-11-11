#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a , b , c , d;
	cin >> a >> b >> c >> d;
	if (a == c) cout << "1";
	else
	{
		cout << "0000";
		return 0;
	}
	if (b[0] == d[0] && b[1] == d[1]) cout << 1;
	else
	{
		cout << "000";
		return 0;
	}
	if (b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') cout << 1;
	else if (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F') cout << 1;
	else
	{
		cout << "00";
		return 0;
	}
	int x = b[2] , y = d[2];
	if (x == y + 1 || x == y - 1) cout << 1;
	else cout << 0;
	return 0;
}
