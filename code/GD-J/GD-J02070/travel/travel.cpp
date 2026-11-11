#include<iostream>
#include<string>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin >>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int a=0,b=0;
	if('A'==s1[2]||s1[2]=='C'||s1[2]=='B'){
		a=1;
	}else{
		a=2;
	}
	if('A'==s2[2]||s2[2]=='C'||s2[2]=='B'){
		b=1;	
	}else {
		b=2;
	}
	if(a==b){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') cout<<1;
	else {
		if(s1[2]=='D'||s2[2]=='D'){
			cout<<0;
			return 0;
		}else if(s1[2]=='F'||s2[2]=='F'){
			cout<<0;
			return 0;
		}
		int xx=s1[2]-'A',yy=s2[2]-'A';
		if((xx-yy)==1||(yy-xx)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
