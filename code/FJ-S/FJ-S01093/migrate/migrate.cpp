#include<bits/stdc++.h>
using namespace std;

const int N = 2000005;

long long c, T;
long long n, d;
long long ans;
long long a[N], nxt[N], pst[N];
__int128 b[N], d2;

__int128 maxn(__int128 xx, __int128 yy)
{
	if(xx > yy)return xx;
	return yy;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		bool f = 1;
		__int128 nw, tmp;
		for(long long i = 1; i <= n; i++)
		{
			cin >> a[i];
			b[i] = a[i];
			d2 = d;
			if(i > 2 && b[i] - b[i - 1] != nw)f = 0;
			nw = b[i] - b[i - 1];
		}
		
		if(f)
		{
			if(d2 < 2 * nw)cout << 0 << '\n';
			else 
			{
				tmp = d2 / nw;
				ans = maxn(0, n - 2 * tmp + 1);
				cout << ans << '\n';
			}
		}
		else
		{
			ans = 0;
			for(long long i = 1; i <= n; i++)pst[i] = 0, nxt[i] = 0;
			for(long long i = 1; i <= n; i++)
			{
				for(long long j = i; j <= n; j++)
				{
					if(b[j] - b[i] > d2)j = n + 1;
					if(j <= n)nxt[i] = j;
				}
			}
			for(long long i = n; i >= 1; i--)
			{
				for(long long j = i; j >= 1; j--)
				{
					if(b[i] - b[j] > d2)j = 0;
					if(j)pst[i] = j;
				}
			}
			for(long long i = 1; i <= n - 3; i++)
			{
				long long j = nxt[nxt[i] - 1];
				for( ; j - 3 >= i; j--)
				{
					if(pst[j] + 1 == nxt[i])ans++;
					else j = 0;
				}
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
