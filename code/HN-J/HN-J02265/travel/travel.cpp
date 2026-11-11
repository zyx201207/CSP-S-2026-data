#include <bits/stdc++.h>
using namespace std;
int t=1;
int main(){
	string a,b,c,d;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	//
	if(d[0]==b[0]&&d[1]==b[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
//
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='C'&&d[2]=='A')||(b[2]=='A'&&d[2]=='C')||(b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
//
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
} 
