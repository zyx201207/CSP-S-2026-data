#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')){
		return true;
	}
	if(a=='D'&&b=='F'){
		return true;
	}
	swap(a,b);
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')){
		return true;
	}
	if(a=='D'&&b=='F'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;cin>>a>>b>>c>>d;
	string x=b.substr(0,2),y=d.substr(0,2);
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&x==y&&((d[2]<='C'&&b[2]<='C')||(d[2]>='D'&&b[2]>='D'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&x==y&&((d[2]<='C'&&b[2]<='C')||(d[2]>='D'&&b[2]>='D'))&&check(b[2],d[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
