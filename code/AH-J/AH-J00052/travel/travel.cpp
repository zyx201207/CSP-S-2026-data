#include<bits/stdc++.h>
using namespace std;
int main(){
	//rp++
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool aa=(a==c);
	bool bb=aa&&(b[0]==d[0])&&(b[1]==d[1]);
	bool cc=bb;
	if(b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A')cc&=1;
	else if(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')cc&=1;
	else cc=0;
	bool dd=cc;
	if(b[2]=='A'&&d[2]=='B')dd&=1;
	else if(b[2]=='B'&&d[2]=='C')dd&=1;
	else if(b[2]=='D'&&d[2]=='E')dd&=1;
	else if(d[2]=='A'&&d[2]=='B')dd&=1;
	else if(d[2]=='B'&&b[2]=='C')dd&=1;
	else if(d[2]=='D'&&b[2]=='E')dd&=1;
	else dd=0;
	cout<<aa<<bb<<cc<<dd;
	return 0;
} 
