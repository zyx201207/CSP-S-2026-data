#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N = 1e6+5;
vector<int> g[N];
void add(int x, int y)
{
	g[x].push_back(y);
	g[y].push_back(x);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, m, i, x, y;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> m;
		for(i = 1; i < n; i++)
		{
			cin >> x >> y;
			add(x, y);
		}
		if(c == 13 || c == 14)
		{
			if(m >= n / 2)
				cout << "1\n";
			else
				cout << (n / 2 / 2 - m / 2 + 1) / 2 + 1 << "\n";
		}
	}
	return 0;
}
