#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	bool f1=0,f2=0,f3=0;
	if(a1==b1){
		cout<<"1";
		f1=1;
	}else{
		cout<<"0";
	}
	if(f1&&(a2[0]==b2[0])&&(a2[1]==b2[1])){
		cout<<"1";
		f2=1;
	}else{
		cout<<"0";
	}
	if(f1&&((a2[2]>'C'&&b2[2]>'C')||(a2[2]<='C'&&b2[2]<='C'))&&f2){
		cout<<"1";
		f3=1;
	}else{
		cout<<"0";
	}
	if(f1&&f2&&f3&&(char(int(a2[2])-1)==b2[2]||char(int(a2[2])+1)==b2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	return 0;
} 
