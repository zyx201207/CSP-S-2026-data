#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, c, e = 0;
	string b, d;
	cin >> a >> b >> c >> d;
	if(a == c) cout << 1;
	else 
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(b[0] == d[0] && b[1] == d[1]) 
	{
		cout << 1;
		if(b[2] >= 'D' && d[2] >= 'D') 
		{
			cout << 1 << 1;
			e = 1;
		}
		if(b[2] <= 'C' && d[2] <= 'C')
		{
			cout << 1;
			e = 1;
			int f, g;
			f = b[2];
			g = d[2];
			if(f + 1 == g || g + 1 == f) cout << 1;
			else cout << 0;
		}
		if(e == 0) cout << 0 << 0; 
	}
	else cout << 0 << 0 << 0;
	return 0;
}
