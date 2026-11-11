#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	f=true;
	cin >> a >> b >> c >> d;
	if (a==c)
	{
		cout << 1;
	}
	else{
		cout << 0;
		f=false;
	}
	if (b[0]==d[0]&&b[1]==d[1]&&f)
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
		f=false;
	}
	if ((b[2]<='C'&&d[2]<='C'&&f)||(b[2]>'C'&&d[2]>'C'&&f))
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
		f=false;
	}
	if ((b[2]+1==d[2]||d[2]+1==b[2])&&b[2]!='C'&&d[2]!='C'&&f)
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
		f=false;
	}
	return 0;
} 
