#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e;
bool x(char x,char y)
{
	if(x=='C'&&y=='D')return 0;
	if(x=='D'&&y=='C')return 0;
	return 1;
}
bool y(char x,char y)
{
	if(x=='E'&&y=='D')return 1;
	if(x=='D'&&y=='E')return 1;
	if(x>='A'&&x<='C'&&y>='A'&&y<='C')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)e=e+'1';
	else e=e+'0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1])e=e+'1';
	else e=e+'0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&y(b[2],d[2])==true)
	{
		e=e+'1';
	}
	else e=e+'0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&abs(b[2]-d[2])==1&&x(b[2],d[2])==true)
	{
		e=e+'1';
	}
	else e=e+'0';
	cout<<e;
	return 0;
} 
