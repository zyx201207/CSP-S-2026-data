#include<bits/stdc++.h>
using namespace std;
long long n,m,k,h;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else {cout<<"0000";return 0;}
	n=(b[0]-'0')*10+(b[1]-'0');
	m=(d[0]-'0')*10+(d[1]-'0');
	if(n==m) cout<<"1";
	else {cout<<"000";return 0;}
	if(b[2]<='C'&&d[2]<='C')
	{
		cout<<"1";
		if(b[2]=='A'&&d[2]=='B') cout<<"1";
		else if(b[2]=='B'&&d[2]=='A') cout<<"1";
		else if(b[2]=='B'&&d[2]=='C') cout<<"1";
		else if(b[2]=='C'&&d[2]=='B') cout<<"1";
		else cout<<"0";
	}
	else if(b[2]>'C'&&d[2]>'C') cout<<"11";
	else cout<<"00";
	return 0;
} 
