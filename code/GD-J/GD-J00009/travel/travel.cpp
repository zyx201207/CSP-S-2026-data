#include<string>
#include<iostream>
using namespace std;
bool check(char x,char y){
	if(x>='A'&&x<='C'&&y>='A'&&y<='C')return true;
	else if(x>='D'&&x<='F'&&y>='D'&&y<='F')return true;
	else return false;
}
bool check1(char x,char y){
	if(x>='A'&&x<='C'){
		if(abs(x-y)==1)return true;
		else return false;
	}else if(x>='D'&&x<='F'){
		if(abs(x-y)==2)return true;
		else return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0;
	if(a==c&b[0]==d[0]&&b[1]==d[1]&&check(b[2],d[2]))cout<<1;
	else cout<<0;
	if(a==c&b[0]==d[0]&&b[1]==d[1]&&check(b[2],d[2])&&check1(b[2],d[2]))cout<<1;
	else cout<<0;
	return 0;
}
