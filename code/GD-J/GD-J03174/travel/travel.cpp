#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	string c1,s1,c2,s2;
	bool f1=false,f2=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		f1=true;
	}
	else{
		cout<<0;
	} 
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f1==true){
		cout<<1;
		f2=true;
	}
	else{
		cout<<0;
	}
	if(f1==true&&f2==true){
		if(s1[2]!='D'&&s2[2]!='D'&&s1[2]!='F'&&s2[2]!='F'){
			cout<<1;
			if(s1[2]=='C'&&s2[2]=='A'||s1[2]=='A'&&s2[2]=='C'){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
		else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
			cout<<1;
			cout<<1;
		}
		else{
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
	}
	freopen("travel.out","w","stdout");
	return 0;
	
} 
