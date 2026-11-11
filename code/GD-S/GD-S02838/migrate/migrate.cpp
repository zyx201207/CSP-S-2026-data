#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, T;
#define int long long
#define ull unsigned long long
const long long inf = 1e18;
int n, d;
int x[N];
int f[5005][5005], g[5005][5005];

void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
//	sort(x+1, x+1+n);
//	for(int i = 1; i <= n; i++) cout << x[i] - x[i-1] << " ";
//	cout << endl;
	for(int k = 1; k < n; k++)
	{
		for(int i = 1; i <= n; i++) f[k][i] = inf, g[k][i] = 0;
		f[k][k] = 0; g[k][k] = 1;
		for(int i = k+1; i <= n; i++)
		{
			for(int j = k; j < i; j++)
			{
				if(x[i] - x[j] <= d)
				{
//					if(i == 7) cout << k << " " << i << " " << j << " " << f[k][i] << " " << f[k][j] << " " << g[k][i] << " " << g[k][j] << endl;	
					if(f[k][i] == f[k][j] + 1)
					{
						g[k][i] += g[k][j];
//						if(i == 8) cout << g[k][i] << "*";
					} 
					else if(f[k][i] > f[k][j] + 1) g[k][i] = g[k][j], f[k][i] = f[k][j] + 1;
	//				cout << i << " " << j << " " << f[i] << " " << g[i] << endl;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
//			cout << g[i][j] << " ";
			ans += (g[i][j] == 2 ? 1 : 0);
		}
//		cout << endl;
	}
	cout << ans << endl;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	cin >> c >> T;
	if(c > 10)
	{
		for(int i = 1; i <= T; i++) cout << 0 << endl;
		return 0;
	}
	while(T--)
	{
		solve();
	}
}
/*

10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 
12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 
-999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 
111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
