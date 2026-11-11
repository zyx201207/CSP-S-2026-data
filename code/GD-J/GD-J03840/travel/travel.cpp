#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	if(a==b){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	c=s1[2];
	d=s2[2];
	if(c<='C'&&d<='C'){
		cout<<"1";
	}else if(c>'C'&&d>'C'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(c-d)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	return 0;
}
