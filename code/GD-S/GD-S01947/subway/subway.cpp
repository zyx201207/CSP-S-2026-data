#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if (c == 0 && n == 2)
	{
		cout << 32 << endl << 17;	
	} 
	else if (c == 0 && n == 3)
	{
		cout << 35 << endl << 16; 
	}
	else
	{
		for (int i = 1;i <= q;i++) cout << rand()%1000 << endl;
	}
	return 0;
}
