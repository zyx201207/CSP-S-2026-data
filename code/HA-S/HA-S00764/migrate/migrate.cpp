#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 2e6 + 10;
const int INF = 1e9;

int c, t, n;
ll d;
ll x[N];
int dist, cnt;

void dfs(int pos, int ed, int sum, int _count)
{
	if (pos >= ed) 
	{ 
		if (sum) _count++;
		if (_count < dist) 
		{
			dist = _count; cnt = 1; 
//			cout << "min\n";
		}
		else if (_count == dist) 
		{
			cnt++;
//			cout << "sum\n";
//			cout << dist << endl;
		}
		return; 
	}
	if (sum + x[pos + 1] - x[pos] <= d && (pos + 1 < ed || sum > 0)) 
	{
//		cout << "111\n";
//		cout << pos + 1 << " " << sum + x[pos + 1] - x[pos] << " " << _count << endl;
		dfs(pos + 1, ed, sum + x[pos + 1] - x[pos], _count);
		
	}
//	cout << "222\n";
	if (sum) 
	{
//		cout << pos + 1 << " " << 0 << " " << _count + 2 << endl;
		dfs(pos + 1, ed, 0, _count + 2);

	}
	else 
	{
//		cout << pos + 1 << " 0 " << _count + 1 << endl;
		dfs(pos + 1, ed, 0, _count + 1);
		
	}
}

inline void solve()
{
	cin >> n >> d;
	
	for (int i = 1; i <= n; ++i) cin >> x[i];
	
	ll ans = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 2; j <= n; ++j)
		{
			cnt = 0;
			dist = INF;
			dfs(i, j, 0, 0);
			if (cnt == 2) 
			{
//				cout << "l: " << i << " r: " << j << endl;
				ans++;
			}
		}
	}

//	dfs(1, 5, 0, 0);
	
	cout << ans << endl;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	
	while (t--) solve();
	
	return 0;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
}
