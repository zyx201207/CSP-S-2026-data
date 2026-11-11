#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>
using namespace std;
int c, T;
int n, d;
int x[2000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	//CCF I LOVE YOU QwQ
	//Pls HELP ME QwQ
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		//A
		int k = x[2] - x[1];
		bool A = 1;
		for (int i = 3; i <= n && A; i++)
			if (x[i] - x[i - 1] != k)
				A = 0;
		if (A)
		{
			if (k >= (d + 1) / 2)
				cout << 0 << endl;
			else
			{
				int tmp = n - 3;
				cout << tmp * (tmp + 1) / 2;
			}
			continue;
		}
		//B
		if (x[n] - x[1] <= 2 * d)
			cout << 0 << endl;
	}
} 
