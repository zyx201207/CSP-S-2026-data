#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string a,x,b,y;
string ans;
int m[700];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> x >> b >> y;
	if(a!=b)
	{
		cout << "0000";
		return 0;
	}
	if(x[0]!=y[0]||x[1]!=y[1])
	{
		cout << "1000";
		return 0;
	}
	if((x[2]<='C')!=(y[2]<='C'))
	{
		cout << "1100";
		return 0;
	}
	m['A']=0;m['B']=1;m['C']=2;m['D']=4;m['F']=5;
	if(abs(m[int(x[2])]-m[int(y[2])])<=1)
	{
		cout << "1111";
	}
	else
	{
		cout << "1110";
	}
	return 0;
}
