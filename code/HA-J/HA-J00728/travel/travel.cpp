#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long x=0,y=0,z=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
	cout<<"1";x=1;}
	else cout<<"0";
	if(x==0){cout<<"000";return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
	cout<<"1";y=1;}
	else cout<<"0";
	if(y==0){cout<<"00";return 0;
	}
	if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))
	{
	cout<<"1";z=1;}
	else cout<<"0";
	if(z==0){cout<<"0";return 0;
	}
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
	cout<<"1";
	else cout<<"0";
	return 0;	
 } 
