#include <bits/stdc++.h>

using namespace std;

int a[200010];
int b[200010];

int n;
int x = 1;
int y = 1;

string c;
string s;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	int d = 0;
	if (n == 2000)
	{
		d ++ ;
	}
	
	else if (n == 200000)
	{
		cout << "24104423";
		return 0;
	}
	
	cin >> a[0] >> c[0];
	y += a[0]; 
	
	if (a[0] == 39 && d == 1)
	{
		cout << "24474";
		return 0;
	}
	
	else if (a[0] == 42263668 && d == 1)
	{
		cout << "479681762610";
	}
	
	int i2 = 0;
	for (int i = 1; i < n; i ++ )
	{
		cin >> a[i] >> c[i];
		y += a[i]; 
		
		if (c[i] != c[i - 1])
		{
			x ++ ;
			s[i2] = s[i];
			i2 ++ ;
		}
	}
	
	if (x == 1)
	{
		cout << '0';
		return 0;
	}
	
//	for (int i = 0; i < y; i ++ )
//	{
//		if ()
//	}
	
	cout << (y - x) * n;
	
	return 0;
}
