#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, k;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1;i < n;i++)
		{
			int u, v;
			cin >> u >> v;
		}
		n /= 2;
		n -= k;
		cout << ceil(n / 4.0) + 1 << "\n";
	}
	return 0;
}
