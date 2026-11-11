#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc, rs, xc, xs;
	cin >> rc >> rs >> xc >> xs;
	bool b = false;
	if(rc == xc)
	{
		cout << 1;
		b = true;
	}
	else
	{
		cout << 0;
	}
	ll r, x;
	r = (rs[0] - '0') * 10 + (rs[1] - '0');
	x = (xs[0] - '0') * 10 + (xs[1] - '0');
	//cout << endl << r << " " << x << endl;
	if(r == x && b)
	{
		cout << 1;
		b = true;
	}
	else
	{
		cout << 0;
		b = false;
	}
	if((rs[2] == 'C' || rs[2] == 'B' || rs[2] == 'A') && (xs[2] == 'C' || xs[2] == 'B' || xs[2] == 'A') && b)
	{
		cout << 1;
		b = true;
	}
	else 
	{
		if((rs[2] == 'F' || rs[2] == 'D') && (xs[2] == 'F' || xs[2] == 'D') && b)
		{
			cout << 1;
			b = true;	
		}
		else
		{
			cout << 0;
			b = false;
		}
	}
	if(!b)
	{
		cout << 0;
	}
	else
	{
		if((int(rs[2] - xs[2]) == 1) || (int(xs[2] - rs[2]) == 1) && b)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	return 0;
} 
