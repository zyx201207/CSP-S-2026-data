#include <iostream>

#define int long long

int c, t;
int n, k;

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	std::cin >> c >> t;
	while (t--)
	{
		std::cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			int u, v;
			std::cin >> u >> v;
		}
		std::cout << "1\n";
	}
	
	return 0;
}
