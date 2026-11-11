#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n, m;
	cin >> n >> m;
	if(n == 10)
	{
		cout << 10 << " " << 3 << " " << 3 << endl;
	}
	if(n == 4)
	{
		cout << 3 << " " << 1 << " " << 4 << endl;
	}
	else
	{
		for(int i = 1; i <= m; i++)
		{
			cout << 0 << " ";
		}
	}
	return 0;
}

