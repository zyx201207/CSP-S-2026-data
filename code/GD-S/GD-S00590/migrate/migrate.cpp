#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int N = 5e3 + 5;

int c, n, d, a[N], cnt[N], dist[N];

void bfs(int s)
{
	queue<int> q; 
	q.push(s); dist[s] = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(dist, -1, sizeof(dist));
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = 1; i <= n; i++)
		{
			if(i == x) continue;
			if(abs(a[x] - a[i]) > d) continue;
			if(dist[i] == -1)
			{
				cnt[i] = 1;
				dist[i] = dist[x] + 1;
				q.push(i);
			}
			else if(dist[x] + 1 == dist[i]) cnt[i]++;
		}
	}
	return;
}

void solve()
{
	cin >> n >> d; int ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(c <= 10)
	{
		for(int i = 1; i <= n; i++)
		{
			bfs(i);
			for(int j = i + 1; j <= n; j++)
			{
				if(cnt[j] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	else
	{
		bfs(1);
		vector<int> v;
		for(int i = 2; i <= n; i++)
		{
			if(cnt[i] == 2)
			{
				v.push_back(i - 1);
				ans++;
			}
		}
		for(int i = 2; i <= n; i++)
		{
			// i + v[j] > n; v[j] > n - i
			auto it = upper_bound(v.begin(), v.end(), n - i);
			if(it == v.end()) ans += v.size();
			else
			{
				int pos = it - v.begin();
				ans += pos;
			}
		}
		cout << ans << endl;
	}
	return;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> c >> t;
	while(t--) solve();
	return 0;	
} 
