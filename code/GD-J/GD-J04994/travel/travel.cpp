#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool x1,x2,x3,x4;
	if(a==c){
		cout<<"1";
		x1=1;
	}
	else{
		cout<<"0"; 
		x1=0;
	} 
	if(x1==1&&(b[0]==d[0]&&b[1]==d[1])){
		cout<<"1";
		x2=1;
	}
	else{
		cout<<"0";
		x2=0;
	} 
	if(x2==1&&(((b[2]<='C'&&b[2]>='A')&&(d[2]<='C'&&d[2]>='A'))||((b[2]<='F'&&b[2]>='D')&&(d[2]<='F'&&d[2]>='D')))){
		cout<<"1";
		x3=1;
	}
	else{
		cout<<"0";	
		x3=0;
	} 
	if(x3==1&&abs(b[2]-d[2])==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
