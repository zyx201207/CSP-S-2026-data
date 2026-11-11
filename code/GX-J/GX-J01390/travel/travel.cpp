#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
char c1,c2;
int p,o;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	c1=b1[2];
	c2=b2[2];
	b1[2]=0;
	b2[2]=0;
	
	if(c1>'C'&&c2<='C'){
		p=1;
	}
	if(c1<='C'&&c2>'C'){
		p=1;
	}

	if(a1==a2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(b1==b2){
		cout<<1;
	}
	else{
		cout<<"000";
		o=1;
		return 0;
	}
	
	if(o==1){
		cout<<0;
	}
	else if(c1<='C'&&c2<='C'){
		cout<<1;
	}
	else if(c1>'C'&&c2>'C'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if(o==1){
		cout<<0;
	}
	else if(c1>'C'&&c2>'C'){
		cout<<1;
	}
	
	else if(p==1){
		cout<<0;
	}
	else if(c1-c2==-1||c1-c2==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
