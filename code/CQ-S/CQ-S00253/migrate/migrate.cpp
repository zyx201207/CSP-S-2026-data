#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 2e6 + 5;
int c, t;
ll x[N];
int nxt[N][22];
int step(int i, int j)
{
	if (i > j) swap(i, j);
	int res = 0;
	for (int k = 20; k >= 0; k--)
		if (nxt[i][k] < j) i = nxt[i][k], res += pow(2, k);
	res++;
//	cout << "\n";
	return res;
}
ll ans = 0;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	cin >> c >> t;
	while (t--)
	{
		int n;
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		
		
		if (c == 11 || c == 12)
		{
			ll diff = x[2] - x[1];
			if (diff >= d) cout << "0\n";
			else cout << max(n - (d / diff) * 2 + 1, 0LL) << "\n";
			continue;
		}
		
		
		for (int i = 1; i <= n; i++)
		{
//			cout << i << ":";
			int l = i, r = n;
			while (l < r)
			{
//				cout << "#";
				int mid = (l + r + 1) / 2;
//				cout << mid << " "; 
//				cout << x[mid] - x[i] << "\n";
				if (x[mid] - x[i] <= d) l = mid;
				else r = mid - 1;
			}
//			cout << l << "\n";
			nxt[i][0] = l;
		}
		for (int k = 1; k < 21; k++)
			for (int i = 1; i <= n; i++)
				nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
//		for (int i = 1; i <= n; i++)
//		{
//			for (int k = 0; k < 21; k++)
//				cout << nxt[i][k] << " ";
//			cout << "\n"; 
//		}
		
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = nxt[i][0] + 1; j <= n; j++)
			{
				int len = step(i, j);
//				cout << len << "\n";
				int two = 0;
				int first = i;
				int round = 0;
				while (nxt[first][0] < j)
				{
					round++;
//					cout << "$";
					if (first == nxt[first][0])
					{
//						cout << ":";
						two = -1;
						break;
					}
					first = nxt[first][0];
//					cout << first << " ";
					if (step(first - 1, j) == len - round && step(first - 2, j) != len - round)
					{
						if (two)
						{
							two = -1;
							break;
						}
						else
						{
							two = 1;
						}
					}
				}
				if (two == 1) ans++;
			}
		}
		cout << ans << "\n";
		ans = 0;
		for (int i = 1; i <= n; i++) x[i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 21; j++)
				nxt[i][j] = 0;
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

