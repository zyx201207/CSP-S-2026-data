#include <bits/stdc++.h>
using namespace std;

int n, a;
long long c = 0;
char b, temp;
bool d = true;
int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		if (temp != b && i != 1)
		{
			d = 0;
			temp = b;
		}
		c += a;
	}
	if (n == 1) cout << 0;
	else if (d = true) cout << "0";
	else cout << c / 2;
	return 0;
}

