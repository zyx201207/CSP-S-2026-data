#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(b[0]!=d[0]||b[1]!=d[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
		cout<<'1';
	else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((b[2]=='A'&&d[2]=='C')||(d[2]=='A'&&b[2]=='C'))
	{
		cout<<'0';
	}
	else
		cout<<'1';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
