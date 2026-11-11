#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1,s2,s3,s4,s5,s6;
	cin>>c1>>s1>>s2>>s3>>c2>>s4>>s5>>s6;
	bool c=false;
	if(c1==c2 && c1!="01" && c1!="16"){
		cout<<1;
		c=true;
	}else{
		cout<<0;
	}
	bool b=false;
	if(s1==s4 && s2==s5 && c){
		cout<<1;
		b=true;
	}else{
		cout<<0;
	}
	bool a=false;
	if(((s3<='C' &&s6<='C') || (s3>'C' && s6>'C')) && b && c){
		cout<<1;
		a=true;
	}else{
		cout<<0;
	}
	if((s3=='A' && s6=='B') || (s3=='B' &&s6=='C') || (s3=='D'&& s6=='F')){
		if(a && c){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((s6=='A' && s3=='B') || (s6=='B' &&s3=='C') || (s6=='D'&& s3=='F')){
		if(a)
			cout<<1;
		else
			cout<<0;
	}else{
		cout<<0;
	}
	return 0;
} 
