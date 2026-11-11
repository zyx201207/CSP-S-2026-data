#include<bits/stdc++.h>
using namespace std;
#define N 305
typedef long long ll;
#define fr(a, b, c) for(ll a = b; a <= c; a++)
#define relx(a, b) (a) = max(a, b)
#define reln(a, b) (a) = min(a, b)
#define mem(a, b) memset(a, b, sizeof(a))
ll a[N], f[N][N], ans[N][N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll t, T, n, d;
	cin >> t >> T;
	while(T--)
	{
		cin >> n >> d;
		mem(f, 0x3f);
		mem(ans, 0);
		fr(i, 1, n)
		{
			cin >> a[i];
		}
		fr(i, 1, n)
		{
			fr(j, 1, n)
			{
				if(abs(a[i] - a[j]) <= d)
				{
					f[i][j] = f[j][i] = 1;
				}
			}
		}
		fr(k, 1, n)
		{
			fr(i, 1, n)
			{
				fr(j, 1, n)
				{
					if(f[i][j] > f[i][k] + f[k][j])
					{
						f[i][j] = f[i][k] + f[k][j];
					}
				}
			}
		}
		fr(k, 1, n)
		{
			fr(i, 1, n)
			{
				fr(j, 1, n)
				{
					if(f[i][j] == f[i][k] + f[k][j])
					{
						ans[i][j]++;
					}
				}
			}
		}
		ll ANS = 0;
		fr(i, 1, n)
		{
			fr(j, i + 1, n)
			{
				if(ans[i][j] == 2)ANS++;
			}
		}
		cout << ANS << '\n';
	}
	return 0;
}
//fc migrate.out migrate.ans
