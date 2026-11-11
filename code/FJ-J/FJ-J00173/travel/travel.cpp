#include<iostream>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<0<<0<<0;
		return 0;
	}
	cout<<1;
	int a1,b1,a2,b2;
	if (s1[2]<='C'){
		a1=0;
	}
	else{
		a1=1;
	} 
	if (s2[2]<='C'){
		a2=0;
	}
	else{
		a2=1;
	} 
	if (s1[2]=='A'){
		b1=0;
	}
	else if (s1[2]=='B'){
		b1=1;
	} 
	else if (s1[2]=='C'){
		b1=2;
	}
	else if (s1[2]=='D'){
		b1=3;
	}else{
		b1=4;
	}
	if (s2[3]=='A'){
		b2=0;
	}
	else if (s2[2]=='B'){
		b2=1;
	} 
	else if (s2[2]=='C'){
		b2=2;
	}
	else if (s2[2]=='D'){
		b2=3;
	}else{
		b2=4;
	}
	if(a1!=a2){
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if((b1-b2)!=1&&(b2-b1)!=1){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
} 
