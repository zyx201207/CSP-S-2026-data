#include <bits/stdc++.h>
#define N 300
using namespace std;
int c, t;
int n, d, x[N];
int minn = INT_MAX, mts = 0;
int answer = 0;
void dfs(int now, int end, int time)
{
	if (now == end)
	{
		if (time < minn)
			minn = time, mts = 1;
		else if (time == minn)
			mts++;
		return;
	}
	int to = now + 1;
	while (to <= end && x[to] - x[now] <= d)
		dfs(to, end, time + 1), to++;
}
int main()
{
	freopen("migrate.in",  "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while (t--)
	{
		answer = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		//
		bool pd = true;
		for (int i = 3; i <= n; i++)
			if (x[i] - x[i-1] != x[i-1] - x[i-2])
			{
				pd = false;
				break;
			}
		if (pd)
		{
			int dr = d / (x[2] - x[1]);
			if (dr == 0)
			{
				cout << 0;
				continue;
			}
			for (int i = 1; i <= dr - 1; i++)
				answer += max(0, n - i - dr + 1);
			cout << answer << "\n";
			continue;
		}
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				mts = 0;
				minn = INT_MAX;
				dfs(i, j, 0);
				if (mts == 2) answer++;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}
