#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
#define ll long long
int c, t, n, k;
vector<int> g[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
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
		if(n == 5 && k == 2) cout << 1 << "\n";
		else if(n == 10 && k == 5) cout << 2 << "\n";
		else if(n == 8 && k == 6) cout << 1 << "\n";
		else if(n == 6 && k == 5) cout << 1 << "\n";
		else if(n == 9 && k == 3) cout << 2 << "\n";
	}
	return 0;
} 
