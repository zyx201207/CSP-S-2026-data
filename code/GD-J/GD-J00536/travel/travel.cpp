#include <bits/stdc++.h>

using namespace std;

string a, b, c, d;

bool check(char c)
{
	return c == 'D' || c == 'F';
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a >> b >> c >> d;
	if(a != c)
	{
		cout << "0000" << endl;
		return 0;
	}
	cout << 1;
	
	if(b.substr(0, 2) == d.substr(0, 2)) cout << 1;
	else
	{
		cout << "000" << endl;
		return 0;
	}
	
	if(check(b[2]) == check(d[2])) cout << 1;
	else
	{
		cout << "00" << endl;
		return 0;
	}
	
	if(abs(b[2] - d[2]) == 1) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
