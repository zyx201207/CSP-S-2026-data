#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
int che,pai,ce,xiang;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++){
		if(a[i]==c[i])che=1;
		else {
		che=0;
		break;
	  }
	}
	if(che==1)cout<<1;
	else cout<<0;
	
	for(int i=0;i<b.size()-1;i++){
		if(che==1&&b[i]==d[i])pai=1;
		else {
		pai=0;
		break;
	  }
	}
		if(pai==1)cout<<1;
	else cout<<0;
	
	
		if(pai==1&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')))ce=1;
		else {
		ce=0;
	  }
		if(ce==1)cout<<1;
	else cout<<0;
	
	if(ce==1&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')))xiang=1;
		else {
		xiang=0;
	  }
		if(xiang==1)cout<<1;
	else cout<<0;
	
	
	
	return 0;
}
