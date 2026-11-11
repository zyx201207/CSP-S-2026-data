#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	string e;
	cin>>a>>b>>c>>d;
	if(a==c) e+="1";
	else e+="0";
	if(b[0]==d[0]&&b[1]==d[1]) e+="1";
	else e+="0";
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')||(b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E')) e+="1";
	else e+="0";
	if(b[2]+1==d[2]||b[2]-1==d[2]) e+="1";
	else e+="0";
	cout<<e;
	return 0;
}
