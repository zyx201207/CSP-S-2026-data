#include<bits/stdc++.h>
#define ll long long
using namespace std;
string x,y,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>a>>b;
	if(x!=a){ cout<<"0000";return 0;}
	if(y[0]!=b[0]||y[1]!=b[1]){ cout<<"1000";return 0;}
	if(y[2]<='C'&&b[2]>'C'){ cout<<"1100";return 0;}
	if(y[2]>'C'&&b[2]<='C'){ cout<<"1100";return 0;}
	if((y[2]=='A'&&b[2]=='B')||(y[2]=='B'&&b[2]=='A')) cout<<"1111";
	else if((y[2]=='C'&&b[2]=='B')||(y[2]=='B'&&b[2]=='C'))
		cout<<"1111";
	else if((y[2]=='D'&&b[2]=='F')||(y[2]=='F'&&b[2]=='D'))
		cout<<"1111";
	else cout<<"1110";
	return 0;
}
