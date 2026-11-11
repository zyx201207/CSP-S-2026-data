#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1!=c3)
	{
		cout << "0000"<<'\n';
		return 0;
	}
	if(c2.substr(0, 2) != c4.substr(0, 2))
	{
		cout << "1000"<<'\n';
		return 0;
	}
	char x1 = c2[2], x2 = c4[2];
	if(!(((x1 >='A'&&x1<='C')&&(x2>='A'&&x2<='C'))||((x1 >='D'&&x1<='F')&&(x2>='D'&&x2<='F'))))
	{
		cout << "1100"<<'\n';
		return 0;
	}
	if(!((int)x1+1 == (int)x2||(int)x1-1 == (int)x2))
	{
		cout << "1110"<<'\n';
		return 0;
	}
	cout << "1111"<<'\n';
	return 0;
}
