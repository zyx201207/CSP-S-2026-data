#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 5e5 + 10;

int n;
ll a[N], m;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		priority_queue <ll, vector <ll>, greater <ll> > q;
		ll sum = 0; int cnt = 0;
//		cout << "i: " << i << endl;
		for (int j = 1; j <= i; ++j)
		{
			q.push(a[i] - a[j]);
//			cout << a[i] - a[j] << " ";
		}
		
//		cout << endl;
		
		while (!q.empty())
		{
			ll t = q.top(); q.pop();
			if (sum + t <= m)
			{
				cnt++;
				sum += t;
			}
			else break;
		}
//		cout << cnt << endl;
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;
	
	return 0;
}
