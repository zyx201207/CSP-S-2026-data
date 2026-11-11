#include <bits/stdc++.h>
using namespace std;
string a,c;
char b[5],d[5];
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>a;
	for(int i=1;i<=3;i++) cin>>b[i];
	cin>>c;
	for(int i=1;i<=3;i++) cin>>d[i];
	if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='A'&&d[3]=='B') cout<<1111;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='B'&&d[3]=='A') cout<<1111;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='A'&&d[3]=='C') cout<<1110;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='C'&&d[3]=='A') cout<<1110;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='B'&&d[3]=='C') cout<<1111;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='C'&&d[3]=='B') cout<<1111;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='D'&&d[3]=='F') cout<<1111;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='F'&&d[3]=='D') cout<<1111;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='A'&&d[3]!='B'&&d[3]!='C') cout<<1100;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='B'&&d[3]!='A'&&d[3]!='C') cout<<1100;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='C'&&d[3]!='A'&&d[3]!='B') cout<<1100;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='D'&&d[3]!='F') cout<<1100;
	else if(a==c&&b[1]==d[1]&&b[2]==d[2]&&b[3]=='F'&&d[3]!='D') cout<<1100;
	else if(a==c&&(b[1]!=d[1]||b[2]!=d[2])) cout<<1000;
	else cout<<"0000";
	return 0;
}

