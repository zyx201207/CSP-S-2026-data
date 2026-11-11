#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a == c)
	{
		a = 1;
		c = 1;
	}
	else
	{
		a = 0;
		c = 0;
	}
	if(b == d)
	{
		b = 1;
		d = 1;
	}
	else
	{
		b = 0;
		d = 0;
	}
	cout << a <<" "<< b <<" "<< c <<" "<< d;
	return 0;
}
