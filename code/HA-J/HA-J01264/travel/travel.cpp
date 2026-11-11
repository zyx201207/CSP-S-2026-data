#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
freopen("travel.in","w",stdin);
freopen("travel.out","c",stdout);
	int a=0,b=0;
	string a1;
	string b1;
	cin>>a>>a1>>b>>b1;
	bool s1=false,s2=false,s3=false,s4=false;
	if(a==b){
		cout<<1;
		s1=true;
	}else{
		cout<<0;
	}
	if(a1[0]==b1[0]&&a1[1]==b1[1]&&s1==true){
		cout<<1;
		s2=true;
	}else{
		cout<<0;
	}
	max(a1[2],b1[2])=='F';
	if(max(a1[2],b1[2])=='F'&&min(a1[2],b1[2])=='D'&&s2==true){
		cout<<1;
		s3=true;
	}else if(max(a1[2],b1[2])=='C'&&s2==true){
		if(min(a1[2],b1[2])=='B'||min(a1[2],b1[2])=='A'){
			cout<<1;
			s3=true;
		}
	}else if(max(a1[2],b1[2])=='B'&&s2==true){
		if(min(a1[2],b1[2])=='A'){
			cout<<1;
			s3=true;
		}
	}else{
		cout<<0;
	}
	if(max(a1[2],b1[2])=='F'&&min(a1[2],b1[2])=='D'&&s3==true){
		cout<<1;
		s4=true;
	}else if(max(a1[2],b1[2])=='C'&&s3==true){
		if(min(a1[2],b1[2])=='B'){
			cout<<1;
			s4=true;
		}
	}else if(max(a1[2],b1[2])=='B'&&s3==true){
		if(min(a1[2],b1[2])=='A'){
			cout<<1;
			s4=true;
		}
	}
	if(s4==false){
		cout<<0;
	}
	return 0;
} 
