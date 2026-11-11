#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int b2,b1,d2,d1;
int main(){
	cin>>a>>b>>c>>d;
	b1=(int(b[0])-48)*10+int(b[1])-48;
	b2=int(b[2]);
	d1=(int(d[0])-48)*10+int(d[1])-48;
	d2=int(d[2]);
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b1==d1){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(65<=b2&&b2<=67){
		if(65<=d2&&d2<=67)cout<<1;
		else {
			cout<<"00";
			return 0;
		}
	}
	if(68<=b2&&b2<=69){
		if(68<=d2&&d2<=69)cout<<1;
		else {
			cout<<00;
			return 0;
		}
	}
	if(b2+1==d2||b2-1==d2)cout<<1;
	else cout<<0;
	return 0;
} 
