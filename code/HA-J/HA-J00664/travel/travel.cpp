#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1 >>s1>>c2>>s2;
	
	int a,b,c;
	if(c1==c2){
		a=1;
		cout << a<<" ";
	}else{
		a=0;
		cout << a<<" ";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==1){
		b= 1;
		cout << b<<" "; 
	}else{
		b=0;
		cout <<b<<" ";
	}
	if(((s1[2] >='A'&&s1[2]<='C'&&s2[2] >='A'&&s2[2]<='C')||(s1[2] >='D'&&s1[2]<='E'&&s2[2] >='D'&&s2[2]<='E'))&&a==1&&b==1){
		c=1;
		cout << c<<" ";
	}else{
		c=0;
		cout << c<<" ";
	}
	if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))&&a==1&&b==1&&c==1){
		cout << "1"<<" ";
	}else{
		cout <<"0"<<" ";
	}
	return 0;
} 
