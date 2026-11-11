#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	int x,y,z,n;
	cin >> a >> c >> b >> d;
	if(a == b)
	{
		 x = 1;
	}
	else
	{
		x = 0;
		y = 0;
		z = 0;
		n = 0;
		cout<< x << y << z << n;
		return 0;
	}
	int g = c.size()-2;
	for(int i = 0;i<=g;i++)
	{
		if(c[i] != d[i])
		{
			y = 0;
			z = 0;
			n = 0;
			cout << x << y << z << n;
			return 0;
		}
	}
	y = 1;
	if((int)c[c.size()-1]+(int)d[d.size()-1]==131||(int)c[c.size()-1]+(int)d[d.size()-1]==132||(int)c[c.size()-1]+(int)d[d.size()-1]==133||(int)c[c.size()-1]+(int)d[d.size()-1]==138)
	{
		z = 1;
	}
	else
	{
		z = 0;
		n = 0;
		cout<< x << y << z << n;
		return 0;
	}
	if((int)c[c.size()-1]-(int)d[d.size()-1]==1||(int)c[c.size()-1]-(int)d[d.size()-1]==-1)
	{
		if((int)c[c.size()-1]+(int)d[d.size()-1]==135)
		{
			n = 0;
			cout<< x << y << z << n;
			return 0;
		}
		else
		{
			n = 1;
		}
	}
	else
	{
		if((int)c[c.size()-1]+(int)d[d.size()-1]==138)
		{
			n = 1;
		}
		else
		{
			n = 0;
			cout<< x << y << z << n;
			return 0;
		}
	}
	cout<< x << y << z << n;
	return 0;
}

	
