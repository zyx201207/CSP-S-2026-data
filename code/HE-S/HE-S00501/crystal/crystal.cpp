#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 55;
int n, m, a[N], sum, mx;
deque<int> dq;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dq.push_back(1);
	mx = 1;
	for(int i = 2; i <= n; i++)
	{
		sum += dq.size() * (a[i] - a[i - 1]);
		while(sum > m)
		{
			sum -= a[i] - a[dq.front()];
			dq.pop_front();
		}
		mx = max(mx, (int)dq.size() + 1);
		dq.push_back(i);
	}
	cout << mx << endl;
	return 0;
}
