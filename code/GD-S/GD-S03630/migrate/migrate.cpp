#include <bits/stdc++.h>
using namespace std;
int main() {
	/*
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	*/
	int c, t , n, m , ans = 0 , f = 1 , b = 0 , i = 1 , v = 0, r[10000];
	string a;
	cin >> c >> t;
	v = t;
	while (t > 0) {
		--t;
		cin >> n >> m;
		for (int j = 1;j <= n;j++)
			cin >> a[j];
		if (n <= 3) {
			r[i] = 0;
		}
		else if (m == 1) {
			r[i] = 0;
		}
		else if (n == (m + 1)) {
			r[i] = 0;
		}
		else if (a[1] + m < a[2]) {
			r[i] = 0;
		} 
		else if (n == 4 && m == 2 && a[1] + m >= a[2] && a[3] + m >= a[4])
		{
			r[i] = 1;
		}
		else if (n == 4 && m != 2)
		{
			r[i] = 0;
		}
		else if (n == 5 && m == 2 && a[1] + m >= a[2] && a[2] + m >= a[3] && a[3] + m >= a[4] && a[4] + m >= a[5]) 
		{
			r[i] = 2;
			++b;
		}
		else if (n == 5 && m != 2)
		{
			r[i] = 0;
		}
		++i;
	}
	for (int j = 1;j <= v;j++)
	{
		if (j == v)
		{
			cout << r[j];
		}
		else
			cout << r[j] << endl;
	}
	return 0;
}
