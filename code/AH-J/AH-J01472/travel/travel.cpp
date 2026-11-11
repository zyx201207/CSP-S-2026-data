#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int x, y;
bool n, m;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	x = b[0] * 10 + b[1];
	y = d[0] * 10 + d[1];
	if(b[2] == 'F' || b[2] == 'D')
		n = 0;
	else
		n = 1;
	if(d[2] == 'F' || d[2] == 'D')
		m = 0;
	else
		m = 1;
		
		
	if(a != c)
	{
		cout << "0000";
		return 0;
	}
	cout << 1;
	if(x != y)
	{
		cout << "000";
		return 0;
	}
	cout << 1;
	if(n != m)
	{
		cout << "00";
		return 0;
	}
	cout << 1;
	if(abs(b[2] - d[2]) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
} 
