#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,b3,d3;
char a1='0',b1='0',c1='0',d1='0';
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	
	if(a!=c)
	{
		cout<<a1<<b1<<c1<<d1;
		return 0;
	}
	else a1='1';
	if(b[0]==d[0]&&b[1]==d[1])b1='1';
	if(b[2]<='C'&&d[2]<='C')c1='1';
	if(b[2]>'C'&&d[2]>'C')c1='1';
	if(a1=='1'&&b1=='1'&&c1=='1')
	{
		if((b[2]+1==d[2]+1-1)||(b[2]-1==d[2]+1-1)){
			d1='1';
		}
	}
	cout<<a1<<b1<<c1<<d1;
	return 0;
}