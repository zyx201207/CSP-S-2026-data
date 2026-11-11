#include<bits/stdc++.h>
using namespace std;

long long c, t, n, d, rlsum, lrsum, ans, a[2000005]; 
	
long long checklr(long long u, long long v, long long sum)
{
	vector<long long> lr;
	long long last = u, pos = 1;
	for (long long i = u; i <= v; i++)
	{
		if (a[i] - a[last] > d)
		{
			sum--;
			lr.push_back(last);
			lrsum += last;
			last = i - 1;
		}
	}
	if (sum >= 0) return lr.size();
	else return 0; 
}

long long rrl(long long u, long long v)
{
	vector<long long> rl;
	long long last = v, pos = 1;
	for (long long i = v; i <= u; i--)
	{
		if (a[i] - a[last] > d)
		{
			rl.push_back(last);
			rlsum += last;
			last = i + 1;
		}
	}
	return rl.size();
}

bool c1(long long u, long long v)
{
	long long l = 1, r = 10000000000, mid;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if (checklr(u, v, mid))
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return (lrsum == rlsum && checklr(u, v, mid) == rrl(u, v));
}

int main()
{
	freopen("migrate.in","r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (long long r = 1; r <= n; r++)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (long long u = 1; u <= d; u++)
		{
			for (int v = u + 3; v <= d; v++)
			{
				if (c1(u, v))
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
