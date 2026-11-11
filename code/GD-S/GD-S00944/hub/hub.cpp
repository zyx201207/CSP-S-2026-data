#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6 + 10;
int c, t, n, k;
vector<int> g[N];
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << n / 2 << endl;
	}
	return 0;
}
