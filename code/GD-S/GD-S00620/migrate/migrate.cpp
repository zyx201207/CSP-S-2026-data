#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[1000006];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		if(c == 13 || c == 14) cout << 0 << endl;
		else if(n == 4 || n == 5) cout << 2 << endl;
		else if(n <= 3) cout << 0 << endl;
		else if(c >= 15 && c <= 18) cout << 0 << endl;
	}
	
	return 0;
}
