#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n,m,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
//	cout<<b[0]<<' '<<d[0]<<' '<<b[1]<<' '<<d[1]<<' '<<b[2]<<' '<<d[2]<<' ';
	n=a[0]+a[1]*10;
	m=c[0]+c[1]*10;
	if(m==n&&m!=1&&m!=16) cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	if(b[1]==d[1]&&b[0]==d[0]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D') cout<<1;
	else if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A') cout<<1;
	else if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A') cout<<1;
	else if(b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D') cout<<1;
	else if(b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B') cout<<1;
	else if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A') cout<<1;
	else{
		cout<<0;
	}
	return 0;
} 
