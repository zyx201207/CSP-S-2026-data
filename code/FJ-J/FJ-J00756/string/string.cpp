#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if (n <= 1)
	{
		cout << 0;
	}
	else if (n <= 2 && n > 1)
	{
		cin >> a >> b >> c >> d;
		if (b == d)
			cout << 0;
		else
			cout << (a+c)/2; 
	}
	else
	{
		cout << n;
	}
	return 0;
}
