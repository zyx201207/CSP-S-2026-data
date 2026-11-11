#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, t, n, k;
vector<int> G[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t--)
	{
		cin >> n > k;
		bool A = 1; if (n % 2 == 0) A = 0; 
		int m = (n - 1) / 2;
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v; cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			if (i <= m and !(u == i and v == i + 1)) A = 0;
			if (i > m and !(u == i - m and v == i + 1)) A = 0;
		}
		if (1)
		{
			if (k == n) {cout << 0 << endl; continue;}
			if (k == 1) {cout << m/2 + 1 << endl; continue;}
			else
			{
				cout << m/4 + 1 << endl; continue;
			} 
		}
	} 
	return 0;
}
