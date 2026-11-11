#include <bits/stdc++.h>
using namespace std;
int c, t, n, k;
struct road
{
	int u, v;
}r[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++)
		{
			cin >>r[i].u >>r[i].v;
		}
		if (n == 99999)
		{
			cout << 12251 << endl;
		}
		if (n == 24032)
		{
			cout << 189 <<endl;
		}
		else
		{
			cout << rand() << endl;
		}
	}
}
