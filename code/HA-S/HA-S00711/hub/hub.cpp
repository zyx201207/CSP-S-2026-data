#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int c, t, n, k;
vector<int> e[N];
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(k == n)
		{
			cout << 0 << "\n";
		}
		else if(k >= n / 2 + 1)
		{
			cout << 1 << "\n";
		}
		else{
			cout << ceil((n / 2 - 1 - k) * 1.0 / 3) + 1<< "\n";
		}
	}
	return 0;
}
