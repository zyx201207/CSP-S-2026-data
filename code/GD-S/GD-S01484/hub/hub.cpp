#include <iostream>
using namespace std;

int n, m;
void solu()
{
	cin >> n >> m;
	for (int i = 1; i < n; ++i)
		cin >> m >> m;
	cout << (n >> 1);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int dxd, T;
	cin >> dxd >> T;
	while (T--)
		solu();
	return 0;
}
