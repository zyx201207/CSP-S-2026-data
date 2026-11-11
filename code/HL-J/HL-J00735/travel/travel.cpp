#include<bits/stdc++.h>
using namespace std;
string s;
int vis,vis2,vis3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	char a=s[0];
	char b=s[1];
	char c=s[3];
	char d=s[4];
	char f=s[5];
	char a1=s[7];
	char b1=s[8];
	char c1=s[10];
	char d1=s[11];
	char f1=s[12];
	if(a==a1&&b==b1){
		cout<<1;
		vis3=1;
	}else{
		cout<<0;
	}
	
	
	
	
	
	if(c==c1&&d==d1&&vis3==1){
		cout<<1;
		vis2=1;
	}
	else{
		cout<<0;
	}
	
	
	
	
	if(f<='C'&&f1<='C'&&vis2==1){
		cout<<1;
		vis=1;
	}
	else if(f<='F'&&f1<='F'&&f>'C'&&f1>'C'&&vis2==1){
		cout<<1;
		vis=1;
	}else{
		cout<<0;
	}
	
	
	
	
	
	if(vis==0){
		cout<<0;
		return 0;
	}
	if(abs(f-f1)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;	
}