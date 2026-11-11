#include<bits/stdc++.h>
using namespace std;

int c, t, n, k, u[200005], v[200005];

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> u[i] >> v[i]; 
	}
	cout << (u[1] + v[1] + u[t] + v[t]) / 4 + u[1] * v[t] / u[t] / v[1];
	return 0;
}
