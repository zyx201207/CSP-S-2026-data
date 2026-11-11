#include<bits/stdc++.h>
using namespace std;
string rn,xn;
string rs,xs;
int main()
{
	freopen(cin,"r");
	freopen(cout,"p");
	cin>>rn>>rs>>xn>>xs;
	int rnum,xnum,rnum2,xnum2;
	rnum=rn[1]-'0'+(rn[0]-'0')*10;
	xnum=xn[1]-'0'+(xn[0]-'0')*10;
	rnum2=rs[1]-'0'+(rs[0]-'0')*10;
	xnum2=xs[1]-'0'+(xs[0]-'0')*10;
	if(rnum==xnum){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(rnum2==xnum2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((rs[2]<'D'&&xs[2]<'D')||(rs[2]>'C'&&xs[2]>'C')){
		cout<<1;
	}else{
		cout<<"00";
	}
	if(abs(rs[2]-xs[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}


