#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream fin("travel.in");
ofstream fout("travel.out");
string a,b,c,d;
char m,n;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	fin>>a>>b>>c>>d;
	if(a==c) fout<<"1";
	else fout<<"0";
	if(b[0]!=d[0]||b[0]!=d[0]) fout<<"0";
	else fout<<"1";
	m=b[2],n=d[2];
	//ut<<m<<n;
	if((m=='A'||m=='B'||m=='C')&&(n=='A'||n=='B'||n=='C')) 
	{
		fout<<"1";
		if((m=='A'&&n=='C')||(m=='C'&&n=='A')) fout<<"0";
		else fout<<"1";
	}
	else 
	{
		if((m=='D'||m=='F')&&(n=='D'||n=='F')) fout<<"11";
		else fout<<"00";
	}
	return 0;
}
