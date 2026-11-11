#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	char a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a='1';
	}
	else{
		a='0';
	}
	if(a=='1'&&s1[0]==s2[0]&&s1[1]==s2[1]){
		b='1';
	}
	else{
		b='0';
	}
	int s12=int(s1[2]),s22=int(s2[2]);
	if((b=='1'&&s12<=67&&s22<=67)||(b=='1'&&s12>=68&&s22>=68)){
		c='1';
	}
	else{
		c='0';
	}
	if((c=='1'&&s12-s22==1)||(c=='1'&&s12-s22==-1)){
		d='1';
	}
	else{
		d='0';
	}
	cout<<a<<b<<c<<d;
	return 0;
}


