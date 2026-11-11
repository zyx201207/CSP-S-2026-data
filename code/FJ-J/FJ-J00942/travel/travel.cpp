#include <bits/stdc++.h>
using namespace std;

string co,so,cl,sl;
string u;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>cl>>sl;
	if(co==cl){
		u+='1';
	}else{
		cout<<"0000";
		return 0;
	}
	string x=so.substr(0,2);
	string y=sl.substr(0,2);
	if(so[2]=='F'){
		so[2]='E';
	}
	if(sl[2]=='F'){
		sl[2]='E';
	}
	int p=so[2]+sl[2];
	if(x==y){
		u+='1';
		if(so[2]<='C' && sl[2]<='C' || so[2]>='D' && sl[2]>='D'){
			u+='1';
		}else{
			u+='0';
		}
		if(abs(int(so[2]-sl[2]))==1 && p!=135){
			u+='1';
		}else{
			u+='0';
		}
	}else{
		u+="000";
	}
	cout<<u;
	return 0;
}
