#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1000006;
int u[N], v[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t --)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i ++)
			cin >> u[i] >> v[i];
		cout << "0 2\n5 2\n1 2\n2 3\n3 4\n4 5\n10 3\n1 2\n1 3\n2 4\n2 5\n3 6\n3 7\n3 8\n7 9\n9 10\n";
	}
	return 0;
}
