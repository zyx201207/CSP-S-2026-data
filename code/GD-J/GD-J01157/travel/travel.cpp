#include <bits/stdc++.h>
using namespace std;
string R,r,X,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> R >> r >> X >> x;
	if (R == X)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if (r[0] == x[0])
	{
		if (r[1] == x[1])
		{
			cout << "1";
		}
		else
		{
			cout << "000";
			return 0;
		}
	}
	if ((r[2] <= 'C' && x[2] <= 'C') or (r[2] > 'C' && x[2] > 'C'))
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if (r[2] > 'C')
	{
		if (r[2]+2 == x[2] or x[2]+2 == r[2])
		{
			cout << "1";
			return 0;
		}
		else
		{
			cout << "0";
			return 0;
		}
	}
	else if (r[2] <= 'C')
	{
		if (r[2]+1 == x[2] or x[2]+1 == r[2])
		{
			cout << "1";
			return 0;
		}
		else
		{
			cout << "0";
			return 0;
		}
	}
	return 0;
} 
