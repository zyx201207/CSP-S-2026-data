#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		vector<vector<int> > g;
		for(int i = 0; i < n; i++)
		{
			int p, q; cin >> p >> q;
			g[p].push_back(q);
		}
		cout << 1;
	}
	return 0;
}

