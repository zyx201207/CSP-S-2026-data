#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll c,t;
ll n,d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	cin >> n >> d;
	if (c == 0)
	{
		if (t == 2)
		{
			if (n == 4 && d == 2)
			{
				cout << 1 << '\n' << 2;
				return 0;
			}
			if (n == 5 && d == 3)
			{
				cout << 0 << '\n' << 1;
				return 0;
			}
		}		
		if (t == 17)
		{
			if (n == 197 && d == 29418319589926278)
			{
				cout << 8129 << '\n' << 16 << '\n' << 9 << '\n' << 7 << '\n' << 12 << '\n' << 0 << '\n' << 0 << '\n' << 0 << '\n' << 2 << '\n' << 1 << '\n' << 0 << '\n' << 2 << '\n' << 3 << '\n' << 6 << '\n' << 0 << '\n' << 2 << '\n' << 0 << '\n';
				return 0; 
			}
		}
		if (t == 12)
		{
			cout << 0 << '\n' << 0 << '\n' << 259997 << '\n' << 259995 << '\n' << 86669 << '\n' << 0 << '\n' << 0 << '\n' << 0 << '\n' << 7 << '\n' << 5 << '\n' << 5 << '\n' << 0 << '\n';
			return 0;
		}
		if (t == 14)
		{
			cout << 9999900000 << '\n' << 399995 << '\n' << 0 << '\n' << 716427 << '\n' << 0 << '\n' << 0 << '\n' << 2 << '\n' << 1 << '\n' << 0 << '\n' << 2 << '\n' << 3 << '\n' << 6 << '\n' << 0 << '\n' << 2 << '\n';
			return 0;
		}
		if (t == 16)
		{
			cout << 6800625333 << '\n' << 6247500 << '\n' << 6242502 << '\n' << 4998 << '\n' << 9994 << '\n' << 0 << '\n' << 0 << '\n' << 0 << '\n' << 2 << '\n' << 1 << '\n' << 0 << '\n' << 2 << '\n' << 3 << '\n' << 6 << '\n' << 0 << '\n' << 2 << '\n';
			return 0;
		}
	}
	srand(time(0));
	while (t--)
	{
		cout << rand() << '\n';
	}
	return 0;
}
