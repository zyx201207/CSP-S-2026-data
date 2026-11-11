#include <bits/stdc++.h>
using namespace std;
bool flag;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string n,m;
	cin >> a >> n >> b >> m;
	int x,y;
	char c1,c2;
	x = (int(n[0] - 48)) + (int(n[1] - 48)) * 10;
	y = (int(m[0] - 48)) + (int(m[1] - 48)) * 10;
	c1 = n[2];
	c2 = m[2];
	if(a == b)
	{
		cout << 1;
		flag = true;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(x == y)
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(((c1 >= 'A' && c1 <= 'C') && (c2 >= 'A' && c2 <= 'C')) || ((c1 >= 'D' && c1 <= 'F') && (c2 >= 'D' && c2 <= 'F')))
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	if(((c1 == 'B') && (c2 == 'A' || c2 == 'C')) || ((c2 == 'B') && (c1 == 'A' || c1 == 'C')) || ((c1 == 'D') && (c2 == 'F')) || ((c2 == 'D') && (c1 == 'F')))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
