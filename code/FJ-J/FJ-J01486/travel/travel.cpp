#include<bits/stdc++.h>
using namespace std;
string a,c;
char b[3],d[3];
bool check1(string a,string c)
{
	if(a==c)
	{
		return true;
	}
	return false; 
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b[1]>>b[2]>>b[3]>>c>>d[1]>>d[2]>>d[3];
	if(check1(a,c))
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[1]==d[1]&&b[2]==d[2])
	{
		cout<<'1';
	}
	else 
	{
		cout<<"000";
		return 0;
	}
	if((b[3]<='C'&&d[3]<='C')||(b[3]>'C'&&d[3]>'C'))
	{
		cout<<'1';
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(b[3]-d[3])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<"0";
		return 0;
	}
	
	return 0;
}
