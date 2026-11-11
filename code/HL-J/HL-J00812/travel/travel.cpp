#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool p=false,c=false,x=false;
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		x=true;
	}
	else{
		cout<<"0";
	}
	if(x==true&&a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<"1";
		p=true;
	}
	else{
		cout<<"0";
	}
	if(p==true&&(a2[2]!='D'&&a2[2]!='E')&&(b2[2]!='D'&&b2[2]!='E')){
		cout<<"1";
		c=true;
	}
	else if(p==true&&(a2[2]=='D'||a2[2]=='E')&&(b2[2]=='D'||b2[2]=='E')){
		cout<<"1";
		c=true;
	}
	else{
		cout<<"0";
	}
	if(c==true&&(a2[2]==b2[2]-1||b2[2]==a2[2]-1)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}