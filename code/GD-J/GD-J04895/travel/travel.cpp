#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		if(s1[2]==s2[2]&&s1[1]==s2[1]){
			if(s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C'||s1[3]>='D'&&s1[3]<='F'&&s2[3]>='D'&&s2[3]<='F'){
				if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='D'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='D'){
					a+='1111';
					cout<<a;
					return 0;
				}
				else{
					a+='1110';
					cout<<a;
				}
			}
	else{
		a+='1100';
		cout<<a;
	}
		}
		else{
		a+='1000';
		cout<<a;
		}	 
	}
	else{
		a+='0000';
		cout<<a;
	}
	return 0;
} 
