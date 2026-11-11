#include <bits/stdc++.h>
using namespace std;

string cs;
const int MAXN = 5 * 1e5 + 5, MAXM = 3 * 1e5 + 5;
int a[MAXN];
int b[MAXM];
int r[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int k = 1; k <= n; ++ k)
	{
//		cout << k << ":\n"; // debug
		memset(r, 0, sizeof(r));
		int l = 0;
		for (int i = k; i <= n; ++ i)
		{
			for (int j = 1; j <= l; ++ j)
			{
				if (r[j] == a[i])
				{
					l = j - 1;
					break;
				}
			}
//			if (k == 6)
//				cout << "L:" << l << '\n';
			r[++ l] = a[i];
//			if (k == 6)
//			{
//				for (int j = 1; j <= l; ++ j)
//					cout << r[j] << ' '; // debug
//				cout << endl; // debug
//			}
		}
		for (int j = 1; j <= l; ++ j)
		{
//			cout << r[j] << ' '; // debug
			++ b[r[j]];
		}
//		cout << endl; // debug
	}
	for (int i = 1; i < m; ++ i)
		cout << b[i] << ' ';
	cout << b[m] << '\n';
	return 0;
}
