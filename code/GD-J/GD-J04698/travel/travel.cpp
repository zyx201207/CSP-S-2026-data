#include <bits/stdc++.h>
using namespace std;
int rn, xn;
string rm, xm;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>rn>>rm>>xn>>xm;
	if(rn != xn)
	{
		cout<<"0000\n";
		return 0;
	}
	cout<<'1';
	if(rm[0] != xm[0] || rm[1] != xm[1])
	{
		cout<<"000\n";
		return 0;
	}
	cout<<'1';
	if(rm[2] > xm[2]) swap(rm, xm);
	if(rm[2] == 'D')
	{
		if(xm[2] != 'F')
		{
			cout<<"00\n";
			return 0;
		}
		cout<<"11\n";
		return 0;
	}
	if(rm[2] == 'C')
	{
		cout<<"00\n";
		return 0;
	}
	if(rm[2] == 'B')
	{
		if(xm[2] != 'C')
		{
			cout<<"00\n";
			return 0;
		}
		cout<<"11\n";
		return 0;
	}
	if(rm[2] == 'A')
	{
		if(xm[2] > 'C')
		{
			cout<<"00\n";
			return 0;
		}
		cout<<'1';
		if(xm[2] == 'B')
		{
			cout<<"1\n";
			return 0;
		}
		cout<<"0\n";
		return 0;
	}
}
