#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,a,b,l,r;
	cin >> a >> x >> b >> y;
	if (a != b)
	{
		cout << "0000";
		return 0;
	}
	if (x[0] != y[0] || x[1] != y[1])
	{
		cout << "1000";
		return 0;
	}
	if ((x[2] == 'D' && y[2] == 'F') || (x[2] == 'F' && y[2] == 'F'))
	{
		cout << "1111";
		return 0;
	}
	if ((x[2] == 'A'&&y[2] == 'B') || (x[2] == 'B' && y[2] == 'A'))
	{
		cout << "1111";
		return 0;
	}
	if ((x[2] == 'C'&&y[2] == 'B') || (x[2] == 'B' && y[2] == 'C'))
	{
		cout << "1111";
		return 0;
	}
	if ((x[2] == 'C'&&y[2] == 'A') || (x[2] == 'A' && y[2] == 'C'))
	{
		cout << "1110";
		return 0;
	}
	cout << "1100";
	
}
