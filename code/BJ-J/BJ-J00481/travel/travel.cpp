#include<bits/stdc++.h>
using namespace std;
int c1,c2;string s1,s2;
bool fun1(){
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		return true;
	}
	return false;
}
bool fun2(){
	if(abs(s1[2]-s2[2])==1){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";return 0;
	}
	if(fun1()){
		cout<<1;
	}
	else{
		cout<<"00";return 0;
	}
	if(fun2()){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
