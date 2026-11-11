#include<bits/stdc++.h> 
using namespace std;
string a,b,c,d;
bool k1 = false;
bool k2 = false;
bool k3 = false;
bool k4 = false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if(a==c)k1 = true;
	if(b[0]==d[0]&&b[1]==d[1])k2 = true;
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))k3 = true;
	if((b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E'))k3 = true;
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')&&(b[2]=='B'&&d[2]=='A'))k4 = true; 
	if((b[2]=='E'&&d[2]=='D')||(b[2]=='D'&&d[2]=='E'))k4 = true; 
	
	if(k1==true&&k2==true&&k3==true&&k4==true)cout<<"1111";
	if(k1==true&&k2==true&&k3==true&&k4==false)cout<<"1110";
	if(k1==true&&k2==true&&k3==false&&k4==false)cout<<"1100";
	if(k1==true&&k2==false)cout<<"1000";
	if(k1==false)cout<<"0000";
	return 0;
}
