#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 26;
int c, t, n, d, a[N], s[N], ans;
deque<int> dq;

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) 
		{
			cin >> a[i];
			while(dq.size() && a[i] - a[dq.front()] > d)
			{
				s[dq.front()] = i - 1;
				dq.pop_front();
			}
			dq.push_back(i);
		}
		while(dq.size())
		{
			s[dq.front()] = n;
			dq.pop_front();
		}
		for(int i = 1; i <= n; i++)
			if(s[i] - 1 > i && s[s[i] - 2] < s[s[i] - 1]) ans += s[s[i] - 1] - s[s[i] - 2];
		cout << ans << endl;
	}
	return 0;
}
