#include <bits/stdc++.h>
using namespace std;
bool sd(string p)
{
	if(p[2]=='D'||p[2]=='F')return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,x,b,y;
	cin >> a >> x >> b >> y;
	if(a!=b)
	{
		cout << "0000";
		return 0;
	}	
	cout << 1;
	if(!(x[1]==y[1]&&x[0]==y[0]))
	{
		cout << "000";
		return 0;
	}
	cout << 1;
	if(sd(x)!=sd(y))
	{
		cout << "00";
		return 0;
	}
	cout << 1;
	if(x[2]=='D'||x[2]=='F'||abs(int(x[2]-y[2]))<=1)
	{
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}
