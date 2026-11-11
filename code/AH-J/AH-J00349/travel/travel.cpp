#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	if(a[0]==c[0] && a[1]==c[1])
	{
		cout <<"1";
	}
	else
	{
		cout <<"0";
	}
	
	if(b[0]==d[0] && b[1]==d[1])
	{
		cout <<"1";
	}
	else
	{
		cout <<"0";
	}
	cout <<"00";
	return 0;
}
