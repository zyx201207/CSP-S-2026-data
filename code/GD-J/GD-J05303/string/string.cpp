#include <bits/stdc++.h>
using namespace std;
string b;
char d;
int main()
{
	bool f = true;
	int n , m , c = 0 , y = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char a;
		cin >> m >> a;
		for (int j = 1; j <= m; j++) b += a;
		y += m;
		if(i != 1 && d != a) f = false;
		d = a;
	}
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	if (f == true)
	{
		cout << 0;
		return 0;
	}
	int t = 0;
	if (y % 2 == 1) t = y / 2 + 1;
	else t = y / 2;
	for (int i = 0; i <= t; i++)
	{
		if(b[i] != b[y - i]) c++;
	}
	cout << c;
	return 0;
}

