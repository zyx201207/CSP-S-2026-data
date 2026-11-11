#include <bits/stdc++.h>
using namespace std;
int a, b, n;
string a2, b2;
int main()
{
	cin >> a >> b;
	while(a > 0)
	{
		a2[n] = a % 2;
		a /= 2;
		n++;
	}
	n = 0;
	while(b > 0)
	{
		b2[n] = b % 2;
		b /= 2;
		n++;
	}
	cout << a2 << endl << b2;
	return 0;
}
