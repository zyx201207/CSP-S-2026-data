#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, n, r[2000005], l[2000005], sto[2000005], pto[2000005], sst[2000005], pst[2000005];
ll d, a[2000005], ssum[2000005], psum[2000005];
void solve()
{
	cin >> n >> d;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int ptr = 0;
	for(int i=1;i<=n;i++)
	{
		if(ptr < i)
		{
			ptr = i;
		}
		while(ptr < n && a[ptr + 1] - a[i] <= d)
		{
			ptr++;
		}
		r[i] = ptr;
	}
	ptr = n + 1;
	for(int i=n;i;i--)
	{
		if(ptr > i)
		{
			ptr = i;
		}
		while(ptr > 1 && a[i] - a[ptr - 1] <= d)
		{
			ptr--;
		}
		l[i] = ptr;
	}
	for(int i=n;i;i--)
	{
		if(r[i] == i)
		{
			sto[i] = i;
			ssum[i] = i;
			sst[i] = 1;
		}
		else
		{
			sto[i] = sto[r[i]];
			ssum[i] = i + ssum[r[i]];
			sst[i] = 1 + sst[r[i]];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(l[i] == i)
		{
			pto[i] = i;
			psum[i] = i;
			pst[i] = 1;
		}
		else
		{
			pto[i] = pto[l[i]];
			psum[i] = i + psum[l[i]];
			pst[i] = 1 + pst[l[i]];
		}
	}
//	cout << "diff : ";
//	for(int i=2;i<=n;i++)
//	{
//		cout << a[i] - a[i - 1] << ' ';
//	}
//	cout << endl;
	ll ans = 0;
	for(int i=1;i<n-1;i++)
	{
		ll S, P;
		if(r[i] > i + 1)
		{
			S = ssum[r[r[i] - 1]] - ssum[r[r[i] - 2]] + sto[i] * (sst[r[r[i] - 1]] != sst[r[r[i] - 2]]);
		}
		else
		{
			S = 0;
		}
		if(l[i] < i && a[i + 1] - a[l[i]] <= d)
		{
			P = 0;
//			cout << "???? " << i << ' ' << l[i] << ' ' << i + 1 << ' ' << a[l[i]] << ' ' << a[i + 1] << endl;
		}
		else
		{
			if(l[i] < i)
			{
				P = (i - l[i] + 1) + psum[l[l[i] + 1]] - psum[l[l[i]]] - pto[i] * (pst[l[l[i]]] != pst[l[l[i] + 1]]);
//				cout << "!!!! " << i << ' ' << i - l[i] + 1 << ' ' << psum[l[l[i] + 1]] - psum[l[l[i]]] << endl;
			}
			else
			{
				P = 1;
			}
		}
//		cout << i << ' ' << S << ' ' << P << ' ' << S * P << endl;
		ans += S * P;
	}
	cout << ans << endl;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> c >> tt;
	while(tt--)
	{
		solve();
	}
	return 0;
}
//0 1
//7 3
//0 2 4 5 6 7 9

//ans = 6
