#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool t,t1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		t=1;
	}else{
		cout<<"0";
	}
	if(s1[0]+s1[1]==s2[0]+s2[1]&&t==1){
		cout<<"1";
		t1=1;
	}else{
		cout<<"0";
	}
	int a,b;
	if(s1[2]<='C'){
		a=1;
	}else{
		a=2;
	}
	if(s2[2]<='C'){
		b=1;
	}else{
		b=2;
	}
	if(a==b&&t1==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]-1==s2[2]&&s1[2]!='D'&&t1==1||s1[2]+1==s2[2]&&s1[2]!='C'&&t1==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
